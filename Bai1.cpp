#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX 100

// Hàm tạo ma trận ngẫu nhiên từ a đến b
void taoMaTran(int a[MAX][MAX], int m, int n, int a_val, int b_val) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = a_val + rand() % (b_val - a_val + 1);
        }
    }
}

// Hàm xuất ma trận
void xuatMaTran(int a[MAX][MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

// Hàm tính và xuất tổng giá trị từng dòng
void tongGiaTriTungDong(int a[MAX][MAX], int m, int n) {
    printf("2. Tong gia tri tung dong:\n");
    for (int i = 0; i < m; i++) {
        int tong = 0;
        for (int j = 0; j < n; j++) {
            tong += a[i][j];
        }
        printf("Tong gia tri dong %d: %d\n", i, tong);
    }
}

// Hàm xuất phần tử lớn nhất trên từng cột
void phanTuLonNhatTungCot(int a[MAX][MAX], int m, int n) {
    printf("3. Phan tu lon nhat tren tung cot:\n");
    for (int j = 0; j < n; j++) {
        int max = a[0][j];
        for (int i = 1; i < m; i++) {
            if (a[i][j] > max) {
                max = a[i][j];
            }
        }
        printf("Phan tu lon nhat cot %d: %d\n", j, max);
    }
}

// Hàm xuất các phần tử thuộc các đường biên
void xuatDuongBien(int a[MAX][MAX], int m, int n) {
    printf("4. Cac phan tu duong bien:\n");
    bool hasElement = false;
    // Duong bien tren
    for (int j = 0; j < n; j++) {
        printf("%d ", a[0][j]);
        hasElement = true;
    }
    // Duong bien duoi
    for (int j = 0; j < n; j++) {
        printf("%d ", a[m - 1][j]);
        hasElement = true;
    }
    // Duong bien trai va phai
    for (int i = 1; i < m - 1; i++) {
        printf("%d ", a[i][0]);
        hasElement = true;
        printf("%d ", a[i][n - 1]);
        hasElement = true;
    }
    if (!hasElement) {
        printf("Khong tim thay!");
    }
    printf("\n");
}

// Hàm kiểm tra phần tử cực đại
bool laCucDai(int a[MAX][MAX], int m, int n, int i, int j) {
    int di[] = { -1, 0, 1, 0 };
    int dj[] = { 0, 1, 0, -1 };
    for (int k = 0; k < 4; k++) {
        int ni = i + di[k];
        int nj = j + dj[k];
        if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
            if (a[i][j] <= a[ni][nj]) {
                return false;
            }
        }
    }
    return true;
}

// Hàm xuất các phần tử cực đại
void xuatCacPhanTuCucDai(int a[MAX][MAX], int m, int n) {
    printf("5. Cac phan tu cuc dai:\n");
    bool hasElement = false;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (laCucDai(a, m, n, i, j)) {
                printf("a[%d][%d] = %d\n", i, j, a[i][j]);
                hasElement = true;
            }
        }
    }
    if (!hasElement) {
        printf("Khong tim thay!\n");
    }
}

// Hàm kiểm tra phần tử hoàng hậu
bool laHoangHau(int a[MAX][MAX], int m, int n, int i, int j) {
    for (int k = 0; k < m; k++) {
        if (a[k][j] > a[i][j]) {
            return false;
        }
    }
    for (int k = 0; k < n; k++) {
        if (a[i][k] > a[i][j]) {
            return false;
        }
    }
    return true;
}

// Hàm xuất các phần tử hoàng hậu
void xuatCacPhanTuHoangHau(int a[MAX][MAX], int m, int n) {
    printf("6. Cac phan tu hoang hau:\n");
    bool hasElement = false;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (laHoangHau(a, m, n, i, j)) {
                printf("a[%d][%d] = %d\n", i, j, a[i][j]);
                hasElement = true;
            }
        }
    }
    if (!hasElement) {
        printf("Khong tim thay!\n");
    }
}

// Hàm kiểm tra phần tử điểm yên ngựa
bool laDiemYenNgua(int a[MAX][MAX], int m, int n, int i, int j) {
    int minInRow = a[i][0];
    int maxInCol = a[0][j];
    for (int k = 1; k < n; k++) {
        if (a[i][k] < minInRow) {
            minInRow = a[i][k];
        }
    }
    for (int k = 1; k < m; k++) {
        if (a[k][j] > maxInCol) {
            maxInCol = a[k][j];
        }
    }
    return (a[i][j] == minInRow && a[i][j] == maxInCol);
}

// Hàm xuất các điểm yên ngựa
void xuatCacDiemYenNgua(int a[MAX][MAX], int m, int n) {
    printf("7. Cac diem yen ngua:\n");
    bool hasElement = false;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (laDiemYenNgua(a, m, n, i, j)) {
                printf("a[%d][%d] = %d\n", i, j, a[i][j]);
                hasElement = true;
            }
        }
    }
    if (!hasElement) {
        printf("Khong tim thay!\n");
    }
}

// Hàm xuất dòng chỉ chứa số chẵn
void xuatDongChiChuaSoChan(int a[MAX][MAX], int m, int n) {
    printf("8. Cac dong chi chua so chan:\n");
    bool hasElement = false;
    for (int i = 0; i < m; i++) {
        bool chiChuaSoChan = true;
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 != 0) {
                chiChuaSoChan = false;
                break;
            }
        }
        if (chiChuaSoChan) {
            for (int j = 0; j < n; j++) {
                printf("%d\t", a[i][j]);
            }
            printf("\n");
            hasElement = true;
        }
    }
    if (!hasElement) {
        printf("Khong tim thay!\n");
    }
}

// Hàm sắp xếp ma trận tăng theo từng dòng
void sapXepTangTheoDong(int a[MAX][MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (a[i][j] > a[i][k]) {
                    int temp = a[i][j];
                    a[i][j] = a[i][k];
                    a[i][k] = temp;
                }
            }
        }
    }
}

int main() {
    srand(time(NULL));

    int a[MAX][MAX];
    int m, n, a_val, b_val;

    // Nhập kích thước ma trận
    printf("Nhap so dong (m) va so cot (n): ");
    if (scanf("%d %d", &m, &n) != 2 || m <= 0 || n <= 0) {
        printf("Nhap khong hop le!\n");
        return 1;
    }

    // Nhập giá trị ngẫu nhiên
    printf("Nhap gia tri bat dau (a) va gia tri ket thuc (b): ");
    if (scanf("%d %d", &a_val, &b_val) != 2 || a_val > b_val) {
        printf("Nhap khong hop le!\n");
        return 1;
    }

    // Tạo ma trận ngẫu nhiên
    taoMaTran(a, m, n, a_val, b_val);
    printf("1. Ma tran ngau nhien:\n");
    xuatMaTran(a, m, n);

    // Xuất tổng giá trị từng dòng
    tongGiaTriTungDong(a, m, n);

    // Xuất phần tử lớn nhất trên từng cột
    phanTuLonNhatTungCot(a, m, n);

    // Xuất các phần tử thuộc các đường biên
    xuatDuongBien(a, m, n);

    // Xuất các phần tử cực đại
    xuatCacPhanTuCucDai(a, m, n);

    // Xuất các phần tử hoàng hậu
    xuatCacPhanTuHoangHau(a, m, n);

    // Xuất các điểm yên ngựa
    xuatCacDiemYenNgua(a, m, n);

    // Xuất dòng chỉ chứa số chẵn
    xuatDongChiChuaSoChan(a, m, n);

    // Sắp xếp ma trận tăng theo từng dòng
    sapXepTangTheoDong(a, m, n);
    printf("9. Ma tran sau khi sap xep theo tung dong:\n");
    xuatMaTran(a, m, n);

    return 0;
}