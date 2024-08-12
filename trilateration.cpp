#include <iostream>
#include <cmath>

// Function to transpose a 3x3 matrix
void transpose(float in[3][3], float out[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            out[j][i] = in[i][j];
        }
    }
}

// Function to multiply two 3x3 matrices
void multiply(float a[3][3], float b[3][3], float out[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            out[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                out[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// Function to multiply a 3x3 matrix with a 3x1 vector
void multiplyMatrixVector(float a[3][3], float b[3], float out[3]) {
    for (int i = 0; i < 3; i++) {
        out[i] = 0;
        for (int j = 0; j < 3; j++) {
            out[i] += a[i][j] * b[j];
        }
    }
}

// Function to invert a 3x3 matrix
bool invert(float in[3][3], float out[3][3]) {
    float det = in[0][0] * (in[1][1] * in[2][2] - in[1][2] * in[2][1]) -
                in[0][1] * (in[1][0] * in[2][2] - in[1][2] * in[2][0]) +
                in[0][2] * (in[1][0] * in[2][1] - in[1][1] * in[2][0]);

    if (det == 0) {
        std::cerr << "Matrix is singular and cannot be inverted." << std::endl;
        return false;
    }

    float invdet = 1 / det;

    out[0][0] = (in[1][1] * in[2][2] - in[1][2] * in[2][1]) * invdet;
    out[0][1] = (in[0][2] * in[2][1] - in[0][1] * in[2][2]) * invdet;
    out[0][2] = (in[0][1] * in[1][2] - in[0][2] * in[1][1]) * invdet;
    out[1][0] = (in[1][2] * in[2][0] - in[1][0] * in[2][2]) * invdet;
    out[1][1] = (in[0][0] * in[2][2] - in[0][2] * in[2][0]) * invdet;
    out[1][2] = (in[0][2] * in[1][0] - in[0][0] * in[1][2]) * invdet;
    out[2][0] = (in[1][0] * in[2][1] - in[1][1] * in[2][0]) * invdet;
    out[2][1] = (in[0][1] * in[2][0] - in[0][0] * in[2][1]) * invdet;
    out[2][2] = (in[0][0] * in[1][1] - in[0][1] * in[1][0]) * invdet;

    return true;
}

// Function to solve the trilateration problem
void solveTrilateration(int numAnchors, float x_anchors[], float y_anchors[], float z_anchors[], float r[]) {
    float A[3][3];
    float b[3];
    float x[3]; // To store the position (x, y, z)

    // Build matrices A and b
    for (int i = 0; i < 3; i++) {
        A[i][0] = 2 * (x_anchors[3] - x_anchors[i]);
        A[i][1] = 2 * (y_anchors[3] - y_anchors[i]);
        A[i][2] = 2 * (z_anchors[3] - z_anchors[i]);

        b[i] = (std::pow(x_anchors[3], 2) - std::pow(x_anchors[i], 2)) +
               (std::pow(y_anchors[3], 2) - std::pow(y_anchors[i], 2)) +
               (std::pow(z_anchors[3], 2) - std::pow(z_anchors[i], 2)) +
               (std::pow(r[i], 2) - std::pow(r[3], 2));
    }

    // Transpose of A
    float AT[3][3];
    transpose(A, AT);

    // Calculate ATA = AT * A
    float ATA[3][3];
    multiply(AT, A, ATA);

    // Invert ATA
    float ATAinv[3][3];
    if (!invert(ATA, ATAinv)) {
        return;
    }

    // Calculate ATAinvAT = ATAinv * AT
    float ATAinvAT[3][3];
    multiply(ATAinv, AT, ATAinvAT);

    // Calculate the final position x = ATAinvAT * b
    multiplyMatrixVector(ATAinvAT, b, x);

    // Output the results
    std::cout << "Tag position: (" << x[0] << ", " << x[1] << ", " << x[2] << ")" << std::endl;
}

int main() {
    // Example test with 4 anchors
    const int numAnchors = 4;
    float x_anchors[numAnchors] = {0, 4, 2, 1};
    float y_anchors[numAnchors] = {0, 0, 4, 1};
    float z_anchors[numAnchors] = {0, 0, 0, 1};
    float r[numAnchors] = {2.828, 2.828, 2, 1.732};

    solveTrilateration(numAnchors, x_anchors, y_anchors, z_anchors, r);
    return 0;
}
