#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct ThucUong{
    char ten[30];
    char loai[30];
    int soluong;
    int giatien;
};
void menu(ThucUong Nuoc[], int &n);
void nhapDuLieu(ThucUong Nuoc[], int &n);
void sapXep(ThucUong Nuoc[], int &n);
void hienThi(ThucUong Nuoc[], int &n);
void thongKe(ThucUong Nuoc[], int &n);
void timKiem(ThucUong Nuoc[], int &n);
void luuDanhSach(ThucUong Nuoc[], int &n);
int main(){
    struct ThucUong Nuoc[100];
    int n;
    menu(Nuoc, n);
    return 0;
}
void menu(ThucUong Nuoc[], int &n){
    int choose;
    printf("----------Phan mem quan li ca phe---------");
    do{
        printf("\n1. Nhap du lieu");
	    printf("\n2. Sap xep, thong ke, hien thi");
	    printf("\n3. Tim kiem");
	    printf("\n4. Luu File");
	    printf("\n5. Thoat");
        printf("\nChon: ");
        scanf("%d", &choose);
        fflush(stdin);
        switch(choose){
            case 1:
                nhapDuLieu(Nuoc, n);
                break;
            case 2:
                sapXep(Nuoc, n);
                hienThi(Nuoc, n);
                thongKe(Nuoc, n);
                break;
            case 3:
                timKiem(Nuoc, n);
                break;
            case 4:
                luuDanhSach(Nuoc, n);
                break;
            case 5:
                printf("\n Cam on da su dung dich vu!!!");
                break;
            default:
            printf("Nhap lai:");
            scanf("%d", &choose);
            
        }
    } while (choose != 5);
}
void nhapDuLieu(ThucUong Nuoc[], int &n){
    printf("Nhap so luong thuc uong: ");
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        printf("\nNhap du lieu cho thuc uong thu: %d", i+1);
        printf("\nTen thuc uong: ");
        fflush(stdin);
        gets(Nuoc[i].ten);
        printf("Loai thuc uong: ");
        fflush(stdin);
        gets(Nuoc[i].loai);
        printf("So luong: ");
        scanf("%d", &Nuoc[i].soluong);
        printf("Nhap gia tien thuc uong: ");
        fflush(stdin);
        scanf("%d", &Nuoc[i].giatien);
    }
}
void sapXep(ThucUong Nuoc[], int &n){
    int dem = 0;
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<=n; j++){
            dem = strcmp(Nuoc[i].loai, Nuoc[j].loai); //so sang 2 chuoi loai nuoc
            if(dem < 0){
                ThucUong tmp = Nuoc[i];
                Nuoc[i] = Nuoc[j];
                Nuoc[j] = tmp;
            }
        }
    }
}
void hienThi(ThucUong Nuoc[], int &n){
	printf("\n%5s||%15s||%15s||%10s||%10s", "STT", "Ten", "Loai","So Luong", "Gia Tien");
	for(int i=0; i<n; i++){
		printf("\n%5d||%15s||%15s||%10d||%10d", i+1, Nuoc[i].ten, Nuoc[i].loai, Nuoc[i].soluong, Nuoc[i].giatien);
	}
}
void thongKe(ThucUong Nuoc[], int &n){
	//Thong ke thuc uong theo loai
	int count[n];
    for(int i=0; i<n; i++){
        count[i] = 1;
    }
	for(int i=0; i<n; i++){
		if(count[i] == 0){
			continue;
        }
		for(int j=i+1; j<=n; j++){
			if(count[j] == 0) continue;
			
			if(strcmp(Nuoc[i].loai, Nuoc[j].loai) ==0){
				count[i]++;
				count[j]--;
			}
		}
	}
	
	//Hien thi
	for(int i=0; i<n; i++) {
       // if(Nuoc[i].loai != Nuoc[i+1].loai)
		if(count[i] > 0) {
			printf("\n%10s co %d loai", Nuoc[i].loai, count[i]);
		}
	}
}
void timKiem(ThucUong Nuoc[], int &n){
    int count = 0;
    char loai[30];
    printf("Nhap loai nuoc can tim:");
    fflush(stdin);
    gets(loai);
    for(int i=0; i<n; i++){
        int dem = strcmp(Nuoc[i].loai, loai);
        if(dem == 0){
            if(count == 0){
                printf("\n%5s||%10s||%10s||%6s||%6s", "STT", "Ten", "Loai", "So Luong", "Gia Tien");
            }
            count++;
            printf("\n%5d||%10s||%10s||%6d||%6d", i+1, Nuoc[i].ten, Nuoc[i].loai, Nuoc[i].soluong, Nuoc[i].giatien);
        }
    }
    if(count == 0){
        printf("Khong co loai nuoc nay");
    }
}
void luuDanhSach(ThucUong Nuoc[], int &n){
    //Mở file ở chế độ ghi nhị phân “append”. Tức là sẽ ghi vào cuối của nội dung đã có.
    FILE *danhSach = fopen("D:\\Desktop\\Cafe.bin", "ab");
    // ghi du lieu
    fwrite(Nuoc, sizeof(ThucUong), 3, danhSach);
    // dong file
    fclose(danhSach);
    printf("Da luu file voi ten Cafe.bin!");
}