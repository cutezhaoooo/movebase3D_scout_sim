/**
 *  This file contains classes and methods to construct the world for the robot.
 *  It contains classes to store points, lines, world width and height, and obstacles.
 *  Author: jianzhuozhu
 *  Date: 2021-7-24
 */

#include "execution_classes.h"

using namespace std;
using namespace Eigen;

namespace EXECUTION
{

    Node::Node() : cost_(0.0f) {}
    Node::Node(const Node &node)
    {
        children_ = node.children_;
        parent_ = node.parent_;
        position_ = node.position_;
        cost_ = node.cost_;

        plane_ = new Plane;
        if (node.plane_ != NULL)
            *plane_ = *node.plane_;
    }
    Node::~Node()
    {
        delete plane_;
        plane_ = NULL;
    }

    Path::Path() : cost_(INF), type_(Empty) {}
    Path::~Path() {}

    Plane::Plane() {}
    Plane::Plane(const Eigen::Vector3d &p_surface, World *world, const double &radius, const FitPlaneArg &arg)
    {
        init_coord = project2plane(p_surface);
        Vector3d ball_center = world->coordRounding(p_surface);
        float resolution = world->getResolution();

        int fit_num = static_cast<int>(radius / resolution);
        Matrix<bool, Dynamic, Dynamic> vac(2 * fit_num + 1, 2 * fit_num + 1);
        int vac_cout_init = (2 * fit_num + 1) * (2 * fit_num + 1);
        for (int i = -fit_num; i <= fit_num; i++)
        {
            for (int j = -fit_num; j <= fit_num; j++)
            {
                vac(i + fit_num, j + fit_num) = false;
                for (int k = -3; k <= 3; k++)
                {
                    Vector3d point = ball_center + resolution * Vector3d(i, j, k);

                    if (world->isInsideBorder(point) && !world->isFree(point))
                    {
                        plane_pts.push_back(point);
                        if (!vac(i + fit_num, j + fit_num))
                        {
                            vac(i + fit_num, j + fit_num) = true;
                            vac_cout_init--;
                        }
                    }
                }
            }
        }

        size_t pt_num = plane_pts.size();
        Vector3d center;
        for (const auto &pt : plane_pts)
            center += pt;
        center /= pt_num;
        MatrixXd A(pt_num, 3);
        for (size_t i = 0; i < pt_num; i++)
            A.row(i) = plane_pts[i] - center;

        // 创建了一个svd对象 对矩阵A进行奇异值分解
        JacobiSVD<MatrixXd> svd(A, ComputeFullV);
        // 选取这个矩阵的第三列
        normal_vector = svd.matrixV().col(2);

        // calculate indicator1:flatness
        float flatness = 0;
        for (size_t i = 0; i < pt_num; i++)
            flatness += powf(normal_vector.dot(A.row(i)), 4);
        flatness /= (1 + pt_num);

        // calculate indicator2:slope
        Vector3d z_axies(0, 0, 1);
        float slope = 180.0f * (float)acos(z_axies.dot(normal_vector)) / PI;

        // calculate indicator3:sparsity
        float sparsity = 0.0f;

        if (vac_cout_init > 0)
        {
            int vac_cout = 0;
            MatrixXd M_vac(2, vac_cout_init);
            for (int i = 0; i < vac.rows(); i++)
            {
                for (int j = 0; j < vac.cols(); j++)
                {
                    if (!vac(i, j))
                    {
                        M_vac(0, vac_cout) = i;
                        M_vac(1, vac_cout) = j;
                        vac_cout++;
                    }
                }
            }

            MatrixXd meanVec = M_vac.colwise().mean();
            MatrixXd zeroMeanMat = M_vac;
            RowVectorXd meanVecRow(RowVectorXd::Map(meanVec.data(), M_vac.cols()));
            zeroMeanMat.rowwise() -= meanVecRow;
            MatrixXd covMat = (zeroMeanMat.adjoint() * zeroMeanMat) / float(M_vac.rows());
            float trace = (covMat.transpose() * covMat(0, 0)).trace();
            float ratio = vac_cout / (float)(vac.rows() * vac.cols());

            if (ratio > arg.ratio_max_)
                sparsity = 1;
            else if (ratio > arg.ratio_min_ && ratio < arg.ratio_max_ && (1 / trace) > arg.conv_thre_)
                // sparsity = ratio;
                sparsity = (ratio - arg.ratio_min_) / (arg.ratio_max_ - arg.ratio_min_);
            else
                sparsity = 0;
        }

        // The traversability is linear combination of the three indicators
        traversability = arg.w_total_ * (arg.w_flatness_ * flatness + arg.w_slope_ * slope + arg.w_sparsity_ * sparsity);
        traversability = (1 < traversability) ? 1 : traversability;
    }

    World::World(const float &resolution) : resolution_(resolution)
    {
        // 默认的resolution是0.1
        // 初始化下限是正无穷
        lowerbound_ = INF * Vector3d::Ones();
        // 上限是负无穷
        upperbound_ = -INF * Vector3d::Ones();
        idx_count_ = Vector3i::Zero();
    }

    World::~World() { clearMap(); }

    void World::clearMap()
    {
        if (has_map_)
        {
            for (int i = 0; i < idx_count_(0); i++)
            {
                for (int j = 0; j < idx_count_(1); j++)
                {
                    delete[] grid_map_[i][j];
                    grid_map_[i][j] = NULL;
                }
                delete[] grid_map_[i];
                grid_map_[i] = NULL;
            }
            delete[] grid_map_;
            grid_map_ = NULL;
        }
    }

    void World::initGridMap(const Vector3d &lowerbound, const Vector3d &upperbound)
    {
        lowerbound_ = lowerbound;
        upperbound_ = upperbound;
        idx_count_ = ((upperbound_ - lowerbound_) / resolution_).cast<int>() + Eigen::Vector3i::Ones();
        grid_map_ = new bool **[idx_count_(0)];
        for (int i = 0; i < idx_count_(0); i++)
        {
            grid_map_[i] = new bool *[idx_count_(1)];
            for (int j = 0; j < idx_count_(1); j++)
            {
                grid_map_[i][j] = new bool[idx_count_(2)];
                memset(grid_map_[i][j], true, idx_count_(2) * sizeof(bool));
            }
        }
        has_map_ = true;
    }

    void World::initGridMap(const pcl::PointCloud<pcl::PointXYZ> &cloud)
    {
        if (cloud.points.empty())
        {
            ROS_ERROR("Can not initialize the map with an empty point cloud!");
            return;
        }
        clearMap();

        for (const auto &pt : cloud.points)
        {
            // 遍历传入map的点云
            // 初始的lowerbound_是正无穷
            // 初始的upperbound_是负无穷
            
            if (pt.x < lowerbound_(0))
                // 
                lowerbound_(0) = pt.x;
            if (pt.y < lowerbound_(1))
                lowerbound_(1) = pt.y;
            if (pt.z < lowerbound_(2))
                lowerbound_(2) = pt.z;
            if (pt.x > upperbound_(0))
                upperbound_(0) = pt.x;
            if (pt.y > upperbound_(1))
                upperbound_(1) = pt.y;
            if (pt.z + 1.0 > upperbound_(2))
                upperbound_(2) = pt.z + 1.0;
        }

        idx_count_ = ((upperbound_ - lowerbound_) / resolution_).cast<int>() + Eigen::Vector3i::Ones();

        grid_map_ = new bool **[idx_count_(0)];
        for (int i = 0; i < idx_count_(0); i++)
        {
            grid_map_[i] = new bool *[idx_count_(1)];
            for (int j = 0; j < idx_count_(1); j++)
            {
                grid_map_[i][j] = new bool[idx_count_(2)];
                memset(grid_map_[i][j], true, idx_count_(2) * sizeof(bool));
            }
        }
        has_map_ = true;
    }

    /**
     * 碰撞检测
     * node_start :起始节点，包含位置和法向量信息
     * node_end:目标节点，包含位置和法向量信息
     */
    // NOTE:碰撞检测
    bool World::collisionFree(const Node *node_start, const Node *node_end)
    {
        Vector3d e_z, e_y, e_x;
        Matrix3d rotation_matrix;

        // 表示起始节点到目标节点的位移向量
        Vector3d diff_pos = node_end->position_ - node_start->position_;

        // 表示起始节点和目标节点之间的法向量差值
        Vector3d diff_norm_vector = node_end->plane_->normal_vector - node_start->plane_->normal_vector;

        size_t step = 20; // 采样步数，表示路径上需要检查的中间点的数量（固定为 20 步）
        // size_t step = std::ceil(diff_pos.norm() / resolution_)  //基于路径长度动态调整步数
        bool isfree = true;

        // 通过 线性插值 的方式生成路径上的检查点
        for (size_t i = 0; i <= step; i++)
        {
            Vector3d check_center = node_start->position_ + diff_pos * i / (double)step; // 路径上第 i 个检查点的位置

            e_z = node_start->plane_->normal_vector + diff_norm_vector * i / (double)step; // 路径上第 i 个检查点的法向量，通过插值计算
            e_z.normalize();                                                               // 法向量归一化

            e_x = diff_pos - (diff_pos.dot(e_z)) * diff_pos; // 与路径方向正交的向量
            e_x.normalize();

            e_y = e_z.cross(e_x); // e_y 与 e_z 和 e_x 两者正交

            // 使用 e_x、e_y 和 e_z 构造旋转矩阵，完成局部坐标系到世界坐标系的转换。
            rotation_matrix << e_x(0), e_y(0), e_z(0),
                e_x(1), e_y(1), e_z(1),
                e_x(2), e_y(2), e_z(2);

            // 在每个检查点周围的一小块区域中，遍历多个点以检查障碍物
            Vector3d check_point;
            for (int y = -2; y <= 2; y++)
            {
                for (int z = -2; z <= 2; z++)
                {
                    check_point = check_center + rotation_matrix * Vector3d(0, 0.15 * y, 0.1 * z);  //通过旋转矩阵将偏移点变换到世界坐标系
                    if (!isFree(check_point))   //检查 check_point 是否处于自由空间
                        return false;
                }
            }
        }
        return isfree;
    }

void World::setObs(const Eigen::Vector3d &point) {
        if (!has_map_) {
            ROS_ERROR("Grid map has not been initialized.");
            return;
        }

        Vector3i idx = coord2index(point);

        // 检查是否为极端无效值
        if (idx(0) == INT_MIN || idx(1) == INT_MIN || idx(2) == INT_MIN) {
            // ROS_ERROR_STREAM("Detected invalid index value(s): (" << idx(0) << ", " << idx(1) << ", " << idx(2) << "). Skipping setting obstacle.");
            return;
        }

        // 原有的无效索引检查
        if (idx(0) == -1 && idx(1) == -1 && idx(2) == -1) {
            // ROS_ERROR_STREAM("Point (" << point.transpose() << ") cannot be set as obstacle due to being out of bounds.");
            return;
        }

        // std::cout << " with Index: (" 
        //           << idx(0) << ", " << idx(1) << ", " << idx(2) << ")" << std::endl;

        grid_map_[idx(0)][idx(1)][idx(2)] = false;
    }

    void World::setObsReverse(const Vector3d &point)
    {
        Vector3i idx = coord2index(point);
        grid_map_[idx(0)][idx(1)][idx(2)] = true;
    }
    bool World::isFree(const Vector3d &point)
    {
        Vector3i idx = coord2index(point);
        bool is_free = isInsideBorder(idx) && grid_map_[idx(0)][idx(1)][idx(2)];
        return is_free;
    }
    bool World::isOut(const Vector3d &point)
    {
        Vector3i idx = coord2index(point);
        bool is_free = isInsideBorder(idx);
        return is_free;
    }

    Vector3d World::coordRounding(const Vector3d &coord)
    {
        return index2coord(coord2index(coord));
    }

    bool World::project2surface(const float &x, const float &y, Vector3d *p_surface)
    {
        // 将二维坐标投影到三维空间的表面
        bool ifsuccess = false;
        // 先x和y确定在三维空间的范围内
        if (x >= lowerbound_(0) && x <= upperbound_(0) && y >= lowerbound_(1) && y <= upperbound_(1))
        {
            // 然后确定z的范围
            for (float z = lowerbound_(2); z < upperbound_(2); z += resolution_)
            {
                if (!isFree(x, y, z) && isFree(x, y, z + resolution_))
                {
                    // 这样就确定了三维的z坐标点 结合传入的x和y坐标就可以确定这点的投影坐标
                    *p_surface = Vector3d(x, y, z);
                    ifsuccess = true;
                    break;
                }
            }
        }
        return ifsuccess;
    }

    bool World::isInsideBorder(const Vector3i &index)
    {
        return index(0) >= 0 &&
               index(1) >= 0 &&
               index(2) >= 0 &&
               index(0) < idx_count_(0) &&
               index(1) < idx_count_(1) &&
               index(2) < idx_count_(2);
    }
}
