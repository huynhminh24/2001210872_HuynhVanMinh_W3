#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

// Hàm xuất các phần tử trên đường chéo chính
void xuatDuongCheoChinh(int n, int** a) {
    printf("2. Cac phan tu tren duong cheo chinh:\n");
    for (int i = 0; i < n; i++) {
        printf("%3d ", a[i][i]);
    }
    printf("\n");
}

// Hàm xuất các phần tử thuộc đường chéo song song với đường chéo chính
void xuatDuongCheoPhu(int n, int** a) {
    printf("3. Cac phan tu tren duong cheo phu:\n");
    for (int i = 0; i < n; i++) {
        printf("%3d ", a[i][n - i - 1]);
    }
    printf("\n");
}

// Hàm tìm phần tử max thuộc tam giác trên của đường chéo chính
int timMaxTamGiacTren(int n, int** a) {
    int max = a[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (a[i][j] > max) {
                max = a[i][j];
            }
        }
    }
    return max;
}

// Hàm sắp xếp ma trận tăng dần theo kiểu zic-zắc
void sapXepZicZac(int n, int** a) {
    int* temp = (int*)malloc(n * n * sizeof(int));
    int index = 0;

    // Chuyển ma trận thành mảng
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[index++] = a[i][j];
        }
    }

    // Sắp xếp mảng
    for (int i = 0; i < n * n - 1; i++) {
        for (int j = i + 1; j < n * n; j++) {
            if (temp[i] > temp[j]) {
                int swap = temp[i];
                temp[i] = temp[j];
                temp[j] = swap;
            }
        }
    }

    // Chuyển mảng trở lại ma trận theo kiểu zic-zắc
    index = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++) {
                a[i][j] = temp[index++];
            }
        }
        else {
            for (int j = n - 1; j >= 0; j--) {
                a[i][j] = temp[index++];
            }
        }
    }

    free(temp);
}

// Hàm sắp xếp đường chéo chính tăng dần từ trên xuống dưới
void sapXepDuongCheoChinh(int n, int** a) {
    int* temp = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        temp[i] = a[i][i];
    }

    // Sắp xếp mảng temp
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (temp[i] > temp[j]) {
                int swap = temp[i];
                temp[i] = temp[j];
                temp[j] = swap;
            }
        }
    }

    // Gán giá trị đã sắp xếp vào đường chéo chính
    for (int i = 0; i < n; i++) {
        a[i][i] = temp[i];
    }

    free(temp);
}

// Hàm kiểm tra giá trị nhập vào
int nhapGiaTri() {
    int n;
    int result;
    char c;

    do {
        printf("Nhap cap cua ma tran (n >= %d): ", MIN_N);
        result = scanf("%d", &n);

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

    printf("1. Ma tran ban dau:\n");
    xuatMaTran(n, a);

    xuatDuongCheoChinh(n, a);
    xuatDuongCheoPhu(n, a);

    int maxTamGiacTren = timMaxTamGiacTren(n, a);
    printf("4. Phan tu lon nhat thuoc tam giac tren cua duong cheo chinh: %d\n", maxTamGiacTren);

    sapXepZicZac(n, a);
    printf("5. Ma tran sau khi sap xep tang dan theo kieu zic-zac:\n");
    xuatMaTran(n, a);

    sapXepDuongCheoChinh(n, a);
    printf("6. Ma tran sau khi sap xep duong cheo chinh tang dan:\n");
    xuatMaTran(n, a);

    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);

    return 0;
}
