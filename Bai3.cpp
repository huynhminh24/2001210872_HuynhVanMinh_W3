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

// Xuất các cột chỉ chứa số lẻ
void xuatCotChiChuaSoLe(int a[MAX][MAX], int m, int n) {
    bool hasElement = false;
    printf("1. Cac cot chi chua so le:\n");
    for (int j = 0; j < n; j++) {
        bool chiSoLe = true;
        for (int i = 0; i < m; i++) {
            if (a[i][j] % 2 == 0) {
                chiSoLe = false;
                break;
            }
        }
        if (chiSoLe) {
            hasElement = true;
            printf("Cot %d: ", j);
            for (int i = 0; i < m; i++) {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
    }
    if (!hasElement) {
        printf("Khong tim thay!\n");
    }
}

// Tìm phần tử lớn nhất trong các phần tử trên biên của ma trận
int timMaxTrenBien(int a[MAX][MAX], int m, int n) {
    int max = a[0][0];
    // Duyệt các phần tử trên biên
    for (int j = 0; j < n; j++) {
        if (a[0][j] > max) max = a[0][j];
        if (a[m - 1][j] > max) max = a[m - 1][j];
    }
    for (int i = 1; i < m - 1; i++) {
        if (a[i][0] > max) max = a[i][0];
        if (a[i][n - 1] > max) max = a[i][n - 1];
    }
    return max;
}

// Trong ma trận có bao nhiêu phần tử có chữ số 2 xuất hiện trong các chữ số của nó
int demPhanTuCoChuSo2(int a[MAX][MAX], int m, int n) {
    int dem = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int num = a[i][j];
            while (num != 0) {
                if (num % 10 == 2) {
                    dem++;
                    break;
                }
                num /= 10;
            }
        }
    }
    return dem;
}

// Xuất các phần tử cực tiểu của ma trận
void xuatCucTieu(int a[MAX][MAX], int m, int n) {
    printf("4. Cac phan tu cuc tieu:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            bool cucTieu = true;
            int di[] = { -1, 0, 1, 0 };
            int dj[] = { 0, 1, 0, -1 };
            for (int k = 0; k < 4; k++) {
                int ni = i + di[k];
                int nj = j + dj[k];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                    if (a[i][j] >= a[ni][nj]) {
                        cucTieu = false;
                        break;
                    }
                }
            }
            if (cucTieu) {
                printf("a[%d][%d] = %d\n", i, j, a[i][j]);
            }
        }
    }
}

// Sắp xếp ma trận sao cho: các dòng có chỉ số lẻ thì tăng dần, còn các dòng có chỉ số chẵn thì giảm dần
void sapXepMaTranDongLeTangChanGiam(int a[MAX][MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if ((i % 2 == 1 && a[i][j] > a[i][k]) || (i % 2 == 0 && a[i][j] < a[i][k])) {
                    int temp = a[i][j];
                    a[i][j] = a[i][k];
                    a[i][k] = temp;
                }
            }
        }
    }
}

// Sắp xếp ma trận sao cho: các cột có chỉ số lẻ thì giảm dần, còn các cột có chỉ số chẵn thì tăng dần
void sapXepMaTranCotLeGiamChanTang(int a[MAX][MAX], int m, int n) {
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m - 1; i++) {
            for (int k = i + 1; k < m; k++) {
                if ((j % 2 == 1 && a[i][j] < a[k][j]) || (j % 2 == 0 && a[i][j] > a[k][j])) {
                    int temp = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = temp;
                }
            }
        }
    }
}

// Kiểm tra các giá trị trong ma trận có giảm dần theo cột và dòng (ziczac)
bool kiemTraZicZac(int a[MAX][MAX], int m, int n) {
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (!(a[i][j] > a[i][j + 1] && a[i][j] > a[i + 1][j])) {
                return false;
            }
        }
    }
    return true;
}

// Liệt kê chỉ số các dòng chứa toàn giá trị chẵn
void lietKeDongToanChan(int a[MAX][MAX], int m, int n) {
    bool hasElement = false;
    printf("8. Cac dong chi chua so chan:\n");
    for (int i = 0; i < m; i++) {
        bool toanChan = true;
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 != 0) {
                toanChan = false;
                break;
            }
        }
        if (toanChan) {
            hasElement = true;
            printf("Dong %d\n", i);
        }
    }
    if (!hasElement) {
        printf("Khong tim thay!\n");
    }
}

// Liệt kê các dòng chứa giá trị giảm dần
void lietKeDongGiamDan(int a[MAX][MAX], int m, int n) {
    bool hasElement = false;
    printf("9. Cac dong co gia tri giam dan:\n");
    for (int i = 0; i < m; i++) {
        bool giamDan = true;
        for (int j = 0; j < n - 1; j++) {
            if (a[i][j] < a[i][j + 1]) {
                giamDan = false;
                break;
            }
        }
        if (giamDan) {
            hasElement = true;
            printf("Dong %d\n", i);
        }
    }
    if (!hasElement) {
        printf("Khong tim thay!\n");
    }
}

// Tìm giá trị xuất hiện nhiều nhất trong ma trận
int giaTriXuatHienNhieuNhat(int a[MAX][MAX], int m, int n) {
    int freq[MAX * MAX] = { 0 };
    int maxFreq = 0, value = a[0][0];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            freq[a[i][j]]++;
            if (freq[a[i][j]] > maxFreq) {
                maxFreq = freq[a[i][j]];
                value = a[i][j];
            }
        }
    }
    return value;
}

// Tìm các chữ số xuất hiện nhiều nhất trong ma trận
void chuSoXuatHienNhieuNhat(int a[MAX][MAX], int m, int n) {
    int freq[10] = { 0 };
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int num = a[i][j];
            while (num != 0) {
                freq[num % 10]++;
                num /= 10;
            }
        }
    }
    int maxFreq = 0;
    for (int i = 0; i < 10; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
        }
    }
    printf("11. Cac chu so xuat hien nhieu nhat: ");
    for (int i = 0; i < 10; i++) {
        if (freq[i] == maxFreq) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Liệt kê các cột có tổng nhỏ nhất trong ma trận
void lietKeCotTongNhoNhat(int a[MAX][MAX], int m, int n) {
    int minSum = 0;
    for (int i = 0; i < m; i++) {
        minSum += a[i][0];
    }
    for (int j = 1; j < n; j++) {
        int sum = 0;
        for (int i = 0; i < m; i++) {
            sum += a[i][j];
        }
        if (sum < minSum) {
            minSum = sum;
        }
    }
    printf("12. Cac cot co tong nho nhat: ");
    for (int j = 0; j < n; j++) {
        int sum = 0;
        for (int i = 0; i < m; i++) {
            sum += a[i][j];
        }
        if (sum == minSum) {
            printf("%d ", j);
        }
    }
    printf("\n");
}

// Hoán vị hai cột i và j trong ma trận
void hoanViCot(int a[MAX][MAX], int m, int n, int i, int j) {
    if (i >= n || j >= n || i < 0 || j < 0) {
        printf("Chi so cot khong hop le\n");
        return;
    }
    for (int k = 0; k < m; k++) {
        int temp = a[k][i];
        a[k][i] = a[k][j];
        a[k][j] = temp;
    }
}

// Hoán vị hai dòng k và l trong ma trận
void hoanViDong(int a[MAX][MAX], int m, int n, int k, int l) {
    if (k >= m || l >= m || k < 0 || l < 0) {
        printf("Chi so dong khong hop le\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        int temp = a[k][i];
        a[k][i] = a[l][i];
        a[l][i] = temp;
    }
}

int main() {
    srand(time(NULL));

    int a[MAX][MAX];
    int m, n, a_val, b_val;

    // Nhập kích thước ma trận
    printf("Nhap so dong (m) va so cot (n): ");
    if (scanf("%d %d", &m, &n) != 2 || m <= 0 || n <= 0 || m > MAX || n > MAX) {
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

    // Xuất ma trận
    printf("Ma tran ngau nhien:\n");
    xuatMaTran(a, m, n);

    // Xuất các cột chỉ chứa số lẻ
    xuatCotChiChuaSoLe(a, m, n);

    // Tìm phần tử lớn nhất trong các phần tử trên biên của ma trận
    int maxBien = timMaxTrenBien(a, m, n);
    printf("2. Phan tu lon nhat tren bien: %d\n", maxBien);

    // Đếm các phần tử có chữ số 2 xuất hiện trong các chữ số của nó
    int demChuSo2 = demPhanTuCoChuSo2(a, m, n);
    printf("3. So phan tu co chu so 2: %d\n", demChuSo2);

    // Xuất các phần tử cực tiểu của ma trận
    xuatCucTieu(a, m, n);

    // Sắp xếp ma trận sao cho: các dòng có chỉ số lẻ thì tăng dần, còn các dòng có chỉ số chẵn thì giảm dần
    sapXepMaTranDongLeTangChanGiam(a, m, n);
    printf("5. Ma tran sau khi sap xep dong le tang, chan giam:\n");
    xuatMaTran(a, m, n);

    // Sắp xếp ma trận sao cho: các cột có chỉ số lẻ thì giảm dần, còn các cột có chỉ số chẵn thì tăng dần
    sapXepMaTranCotLeGiamChanTang(a, m, n);
    printf("6. Ma tran sau khi sap xep cot le giam, chan tang:\n");
    xuatMaTran(a, m, n);

    // Kiểm tra các giá trị trong ma trận có giảm dần theo cột và dòng (ziczac)
    bool ziczac = kiemTraZicZac(a, m, n);
    printf("7. Ma tran giam dan theo cot va dong (ziczac): %s\n", ziczac ? "Co!" : "Khong co!");

    // Liệt kê chỉ số các dòng chứa toàn giá trị chẵn
    lietKeDongToanChan(a, m, n);

    // Liệt kê các dòng chứa giá trị giảm dần
    lietKeDongGiamDan(a, m, n);

    // Tìm giá trị xuất hiện nhiều nhất trong ma trận
    int giaTriNhieuNhat = giaTriXuatHienNhieuNhat(a, m, n);
    printf("10. Gia tri xuat hien nhieu nhat: %d\n", giaTriNhieuNhat);

    // Tìm các chữ số xuất hiện nhiều nhất trong ma trận
    chuSoXuatHienNhieuNhat(a, m, n);

    // Liệt kê các cột có tổng nhỏ nhất trong ma trận
    lietKeCotTongNhoNhat(a, m, n);

    // Hoán vị hai cột i và j trong ma trận
    int i, j;
    printf("13. Nhap chi so hai cot can hoan vi: ");
    scanf("%d %d", &i, &j);
    hoanViCot(a, m, n, i, j);
    printf("Ma tran sau khi hoan vi cot %d va %d:\n", i, j);
    xuatMaTran(a, m, n);

    // Hoán vị hai dòng k và l trong ma trận
    int k, l;
    printf("14. Nhap chi so hai dong can hoan vi: ");
    scanf("%d %d", &k, &l);
    hoanViDong(a, m, n, k, l);
    printf("Ma tran sau khi hoan vi dong %d va %d:\n", k, l);
    xuatMaTran(a, m, n);

    return 0;
}
