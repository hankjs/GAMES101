#define _USE_MATH_DEFINES
#include <cmath>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Dense>
#include <iostream>

int main() {
    /* 
     * PA 0
     * 给定一个点 P=(2,1), 
     * 将该点绕原点先逆时针旋转 45◦，
     * 再平移 (1,2),
     * 计算出 变换后点的坐标（要求用齐次坐标进行计算）。
     * */
    // TO DO: Define point P
    Eigen::Vector3f P(2.0f, 1.0f, 1.0f);
    // TO DO: Define rotation matrix M
    double theta = (45.0f / 180.0f) * M_PI;
    Eigen::Matrix3f rotation, translate;
    rotation <<
        cos(theta), -1 * sin(theta), 0, // first row
        sin(theta), cos(theta), 0, // second row
        0, 0, 1.0f; // third row
    std::cout << "旋转45°矩阵" << std::endl;
    std::cout << rotation << std::endl;

    translate <<
        1, 0, 1.0f, // first row
        0, 1, 2.0f, // second row
        0, 0, 1.0f; // third row
    std::cout << "平移矩阵" << std::endl;
    std::cout << translate << std::endl;

    // TO DO: M * P
    Eigen::Matrix3f M;
    M = translate * rotation;
    std::cout << "旋转45° + 平移矩阵" << std::endl;
    std::cout << M << std::endl;

    /** 
     * 旋转45°
     */
    Eigen::Vector3f P1;
    P1 = rotation * P;
    std::cout << "旋转45°" << std::endl;
    std::cout << P1 << std::endl;

    /** 
     * 旋转45° + 平移
     */
    Eigen::Vector3f P2;
    P2 = M * P;
    std::cout << "旋转45° + 平移" << std::endl;
    std::cout << P2 << std::endl;
    return 0;
}