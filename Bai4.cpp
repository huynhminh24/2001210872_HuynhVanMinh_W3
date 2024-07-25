#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MIN_N 5

// Hàm tạo ma trận vuông với số nguyên ngẫu nhiên
void taoMaTran(int n, int** a) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % 100; // số ngẫu nhiên trong khoảng 0-99
        }
    }
}

// Hàm xuất ma trận
void xuatMaTran(int n, int** a) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", a[i][j]);
        }
        printf("\n");
    }
}

// Hàm sắp xếp đường chéo phụ tăng dần
void sapXepDuongCheoPhuTang(int n, int** a) {
    int* duongCheoPhu = (int*)malloc(2 * n * sizeof(int)); // Tối đa 2n phần tử

    int index = 0;
    // Lấy các phần tử trên đường chéo phụ
    for (int s = 0; s < n; s++) {
        int i = s;
        int j = 0;
        while (i >= 0) {
            duongCheoPhu[index++] = a[i][j++];
            i--;
        }
    }

    for (int s = 1; s < n; s++) {
        int i = n - 1;
        int j = s;
        while (j < n) {
            duongCheoPhu[index++] = a[i--][j++];
        }
    }

    // Sắp xếp tăng dần
    for (int i = 0; i < index - 1; i++) {
        for (int j = i + 1; j < index; j++) {
            if (duongCheoPhu[i] > duongCheoPhu[j]) {
                int temp = duongCheoPhu[i];
                duongCheoPhu[i] = duongCheoPhu[j];
                duongCheoPhu[j] = temp;
            }
        }
    }

    index = 0;
    for (int s = 0; s < n; s++) {
        int i = s;
        int j = 0;
        while (i >= 0) {
            a[i][j++] = duongCheoPhu[index++];
            i--;
        }
    }

    for (int s = 1; s < n; s++) {
        int i = n - 1;
        int j = s;
        while (j < n) {
            a[i--][j++] = duongCheoPhu[index++];
        }
    }

    free(duongCheoPhu);
}

// Hàm sắp xếp ma trận sao cho các dòng có chỉ số lẻ thì tăng dần, còn các dòng có chỉ số chẵn thì giảm dần
void sapXepDongTheoChiSo(int n, int** a) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if ((i % 2 == 0 && a[i][j] < a[i][k]) || (i % 2 != 0 && a[i][j] > a[i][k])) {
                    int temp = a[i][j];
                    a[i][j] = a[i][k];
                    a[i][k] = temp;
                }
            }
        }
    }
}

// Hàm sắp xếp ma trận sao cho các cột có chỉ số lẻ thì giảm dần, còn các cột có chỉ số chẵn thì tăng dần
void sapXepCotTheoChiSo(int n, int** a) {
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n - 1; i++) {
            for (int k = i + 1; k < n; k++) {
                if ((j % 2 == 0 && a[i][j] > a[k][j]) || (j % 2 != 0 && a[i][j] < a[k][j])) {
                    int temp = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = temp;
                }
            }
        }
    }
}

// Hàm sắp xếp ma trận sao cho các phần tử trên các đường chéo chính và các đường chéo song song với đường chéo chính tăng dần
void sapXepDuongCheoChinhTang(int n, int** a) {
    int* duongCheoChinh = (int*)malloc(2 * n * sizeof(int)); // Tối đa 2n phần tử

    int index = 0;
    // Lấy các phần tử trên đường chéo chính và các đường chéo song song
    for (int s = 0; s < n; s++) {
        int i = s;
        int j = 0;
        while (i >= 0) {
            duongCheoChinh[index++] = a[i][j++];
            i--;
        }
    }

    for (int s = 1; s < n; s++) {
        int i = n - 1;
        int j = s;
        while (j < n) {
            duongCheoChinh[index++] = a[i--][j++];
        }
    }

    // Sắp xếp tăng dần
    for (int i = 0; i < index - 1; i++) {
        for (int j = i + 1; j < index; j++) {
            if (duongCheoChinh[i] > duongCheoChinh[j]) {
                int temp = duongCheoChinh[i];
                duongCheoChinh[i] = duongCheoChinh[j];
                duongCheoChinh[j] = temp;
            }
        }
    }

    index = 0;
    for (int s = 0; s < n; s++) {
        int i = s;
        int j = 0;
        while (i >= 0) {
            a[i][j++] = duongCheoChinh[index++];
            i--;
        }
    }

    for (int s = 1; s < n; s++) {
        int i = n - 1;
        int j = s;
        while (j < n) {
            a[i--][j++] = duongCheoChinh[index++];
        }
    }

    free(duongCheoChinh);
}

// Hàm di chuyển các phần tử sao cho các phần tử chẵn nằm ở các dòng đầu mảng, các phần tử lẻ nằm ở các dòng cuối mảng
void diChuyenChanLen(int n, int** a) {
    int* temp = (int*)malloc(n * n * sizeof(int));
    int index = 0;

    // Lưu các số chẵn vào mảng tạm
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 == 0) {
                temp[index++] = a[i][j];
            }
        }
    }

    // Lưu các số lẻ vào mảng tạm
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 != 0) {
                temp[index++] = a[i][j];
            }
        }
    }

    index = 0;
    // Đặt các số chẵn vào các dòng đầu của ma trận
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (index < n * n && a[i][j] % 2 == 0) {
                a[i][j] = temp[index++];
            }
        }
    }

    // Đặt các số lẻ vào các dòng cuối của ma trận
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (index < n * n && a[i][j] % 2 != 0) {
                a[i][j] = temp[index++];
            }
        }
    }

    free(temp);
}

// Hàm kiểm tra ma trận có đối xứng qua đường chéo chính không
bool kiemTraDoiXung(int n, int** a) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != a[j][i]) {
                return false;
            }
        }
    }
    return true;
}

int nhapGiaTri() {
    int n;
    int result;
    char c;

    do {
        printf("Nhap cap cua ma tran (n >= %d): ", MIN_N);
        result = scanf_s("%d", &n);

        // Xử lý trường hợp nhập vào không phải số nguyên
        while ((c = getchar()) != '\n' && c != EOF) {}

        if (result != 1 || n < MIN_N) {
            printf("Gia tri khong hop le. Vui long nhap lai.\n");
        }
    } while (result != 1 || n < MIN_N);

    return n;
}

int main() {
    int n = nhapGiaTri();

    int** a = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        a[i] = (int*)malloc(n * sizeof(int));
    }

    taoMaTran(n, a);
    printf("Ma tran ban dau:\n");
    xuatMaTran(n, a);

    sapXepDuongCheoPhuTang(n, a);
    printf("1. Ma tran sau khi sap xep duong cheo phu tang dan:\n");
    xuatMaTran(n, a);

    sapXepDongTheoChiSo(n, a);
    printf("2. Ma tran sau khi sap xep dong:\n");
    xuatMaTran(n, a);

    sapXepCotTheoChiSo(n, a);
    printf("3. Ma tran sau khi sap xep cot:\n");
    xuatMaTran(n, a);

    sapXepDuongCheoChinhTang(n, a);
    printf("4. Ma tran sau khi sap xep duong cheo chinh tang dan:\n");
    xuatMaTran(n, a);

    diChuyenChanLen(n, a);
    printf("5. Ma tran sau khi di chuyen chan va le:\n");
    xuatMaTran(n, a);

    if (kiemTraDoiXung(n, a)) {
        printf("6. Ma tran doi xung qua duong cheo chinh!\n");
    }
    else {
        printf("6. Ma tran khong doi xung qua duong cheo chinh!\n");
    }

    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);

    return 0;
}
