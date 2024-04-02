#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;

void solve_with_palu(const MatrixXd& A, const VectorXd& b, VectorXd& x) {
    // Perform PALU decomposition
    PartialPivLU<MatrixXd> palu(A);
    // Solve Ax = b
    x = palu.solve(b);
}

void solve_with_qr(const MatrixXd& A, const VectorXd& b, VectorXd& x) {
    // Perform QR decomposition
    HouseholderQR<MatrixXd> qr(A);
    // Solve Ax = b
    x = qr.solve(b);
}

double relative_error(const VectorXd& x_true, const VectorXd& x_pred) {
    return (x_true - x_pred).norm() / x_true.norm();
}

int main() {
    // Define the systems
    MatrixXd A1(2, 2);
    VectorXd b1(2);
    A1 << 5.547001962252291e-01, -3.770900990025203e-02,
          8.320502943378437e-01, -9.992887623566787e-01;
    b1 << -5.169911863249772e-01, 1.672384680188350e-01;

    MatrixXd A2(2, 2);
    VectorXd b2(2);
    A2 << 5.547001962252291e-01, -5.540607316466765e-01,
          8.320502943378437e-01, -8.324762492991313e-01;
    b2 << -6.394645785530173e-04, 4.259549612877223e-04;

    MatrixXd A3(2, 2);
    VectorXd b3(2);
    A3 << 5.547001962252291e-01, -5.547001955851905e-01,
          8.320502943378437e-01, -8.320502947645361e-01;
    b3 << -6.400391328043042e-10, 4.266924591433963e-10;

    // True solution
    VectorXd x_true(2);
    x_true << -1.0e+0, -1.0e+00;

    // Solutions using PALU and QR decomposition
    VectorXd x1_palu, x1_qr, x2_palu, x2_qr, x3_palu, x3_qr;
    solve_with_palu(A1, b1, x1_palu);
    solve_with_qr(A1, b1, x1_qr);
    solve_with_palu(A2, b2, x2_palu);
    solve_with_qr(A2, b2, x2_qr);
    solve_with_palu(A3, b3, x3_palu);
    solve_with_qr(A3, b3, x3_qr);

    // Compute relative errors
    std::cout << "Relative error for System 1 (PALU): " << relative_error(x_true, x1_palu) << std::endl;
    std::cout << "Relative error for System 1 (QR): " << relative_error(x_true, x1_qr) << std::endl;
    std::cout << "Relative error for System 2 (PALU): " << relative_error(x_true, x2_palu) << std::endl;
    std::cout << "Relative error for System 2 (QR): " << relative_error(x_true, x2_qr) << std::endl;
    std::cout << "Relative error for System 3 (PALU): " << relative_error(x_true, x3_palu) << std::endl;
    std::cout << "Relative error for System 3 (QR): " << relative_error(x_true, x3_qr) << std::endl;

    return 0;
}
