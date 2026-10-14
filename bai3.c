#include <stdio.h>
#include <string.h>

#define MAX_VE 100

struct VeMayBay {
    char maVe[15];
    char tenHanhKhach[50];
    char hangVe[20];
    float canNangHanhLy;
    double cuocHanhLy;
};

int main() {
    struct VeMayBay danhSachVe[MAX_VE];
    int n, i;
    double tongCuoc = 0;
    int indexMax = 0;
    char searchPNR[15];
    int found = 0;

    printf("Nhap so luong ve may bay: ");
    scanf("%d", &n);

    if (n < 1 || n > 100) {
        printf("So luong khong hop le. Chuong trinh ket thuc!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("\n--- Nhap thong tin ve thu %d ---\n", i + 1);
        
        printf("Ma ve PNR: ");
        scanf("%s", danhSachVe[i].maVe);
        
        while (getchar() != '\n'); 
        
        printf("Ho ten hanh khach: ");
        fgets(danhSachVe[i].tenHanhKhach, sizeof(danhSachVe[i].tenHanhKhach), stdin);
        danhSachVe[i].tenHanhKhach[strcspn(danhSachVe[i].tenHanhKhach, "\n")] = '\0'; 
        
        printf("Hang ve (Business/Deluxe/Eco): ");
        scanf("%s", danhSachVe[i].hangVe);
        
        do {
            printf("Khoi luong hanh ly ky gui (kg): ");
            scanf("%f", &danhSachVe[i].canNangHanhLy);
            if (danhSachVe[i].canNangHanhLy < 0) {
                printf("Loi: Khoi luong khong duoc am. Vui long nhap lai!\n");
            }
        } while (danhSachVe[i].canNangHanhLy < 0);

        if (strcmp(danhSachVe[i].hangVe, "Business") == 0) {
            if (danhSachVe[i].canNangHanhLy > 20.0f) {
                danhSachVe[i].cuocHanhLy = (danhSachVe[i].canNangHanhLy - 20.0f) * 50000.0;
            } else {
                danhSachVe[i].cuocHanhLy = 0;
            }
        } else {
            danhSachVe[i].cuocHanhLy = danhSachVe[i].canNangHanhLy * 50000.0;
        }
    }

    for (i = 0; i < n; i++) {
        tongCuoc += danhSachVe[i].cuocHanhLy;
        if (danhSachVe[i].canNangHanhLy > danhSachVe[indexMax].canNangHanhLy) {
            indexMax = i;
        }
    }

    printf("\n================================== DANH SACH VE MAY BAY CHUYEN BAY ==================================\n");
    printf("%-4s %-12s %-25s %-12s %12s %15s\n", 
           "STT", "MA VE", "HO TEN HANH KHACH", "HANG VE", "HANH LY (KG)", "CUOC PHI (VND)");
    printf("----------------------------------------------------------------------------------------------------\n");
    for