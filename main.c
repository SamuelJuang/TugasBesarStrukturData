#include "header.h"


int main(int argc, char *argv[]){
	Multilist l;
	List L;
	AddressParent ubah;
	DataP DP;
	DataC DC;
	DataH DH;
	int menu=1, menuAdmin, menuAdmin2, cekUser, menuDokter, count=0;
	string username, password, konfirm;
	AddressParent activeDokter;
	int tanggal, bulan;
	char pass[50];
	
	createEmptyList(&L);
	createEmpty(&l);

	do{
		;;;;system("cls");
		movingText();
		white();
		login:
		do{
			system("cls");
			red();
			printf("\n\n");
			kotakAwal();
			gotoxy(31,2);
			white();
			printf("\n\t\t\t*[NOTE] Username/Password : Keluar/Keluar untuk keluar dari program.");
			printf("\n\n");
			gotoxy(31,5);
			printf("\n\t\t\t\t\xB2 \xB2\xB2\xB2 SILAHKAN MASUK \xB2\xB2\xB2 \xB2");
			gotoxy(31,6);
			printf("\n\t\t\tUsername : "); fflush(stdin); gets(username);
			gotoxy(31,7);
			printf("\n\t\t\tPassword : "); readPassword(pass, 50);
			strcpy(password, pass);

			if(strcmp(username,"admincintasatwa")==0 && strcmp(password,"admincintasatwa")==0){
				cekUser=1;
				printf("\n\t\t\t[!] Berhasil Login Sebagai Admin.");
				getch();
				break;
			}else if(!isEmpty(l)){
				if(findUsername(l, username)!=NULL){
					if(strcmp(username, findUsername(l, username)->dataParent.usernameDok)==0 
					&& strcmp(password, findUsername(l, username)->dataParent.passwordDok)==0){
						cekUser=0;
						break;
					}	
				}
				
			}else if(strcmpi(username,"Keluar")==0 && strcmpi(password,"Keluar")==0){
				menu = 0;
				printf("\n\t\t\t[!] Berhasil Keluar Program.");
				getch();
				break;
			}
			printf("\n\t\t\t[!] Password/Username salah.");
			getch();
		}while(true);
		
		printf("\n\t");
		if(cekUser==1){\
			do{
				mDokter:
				system("cls");
				red();
				kotak();
				white();
				menuAdmin = tampilAdmin(menuAdmin);
				
				switch(menuAdmin){
					case 1: 
						do{
							system("cls");
							red();
							kotak();
							white();
							menuAdmin2 = tampilAdmin2(menuAdmin2);
							printf("\n\n");
							
							switch (menuAdmin2){
								case 1 :
									system("cls");
									printf("\n\tTambah data dokter: ");
									printf("\n\t===================================================================");
									do{
										printf("\n\tId Dokter         : ");scanf("%d", &DP.idDokter);
										if(!isUnikParent(l, DP)){
											printf("\t\t[!] ID harus unik.");
										}else{
											break;
										}
									}while(true);
									
									do{
										printf("\tNama Dokter       : ");fflush(stdin);gets(DP.namaDokter);
										if(strlen(DP.namaDokter)==0){
											printf("\t\t[!] Nama tidak boleh kosong.\n");
										}else{
											break;
										}
									}while(true);
									
									do{
										printf("\tTanggal Bergabung : ");fflush(stdin);gets(DP.tanggalBergabung);
										tanggal = atoi(DP.tanggalBergabung);
										bulan = atoi(DP.tanggalBergabung+3);

										if(strlen(DP.tanggalBergabung)!=10){
											printf("\t\t[!] Format Tanggal Salah.\n");
										}else if(DP.tanggalBergabung[2] != '-' || DP.tanggalBergabung[5] != '-'){
											printf("\t\t[!] Format Tanggal Salah.\n");	
										}else if(tanggal > 31 || bulan > 12){
											printf("\t\t[!] Format Tanggal Salah.\n");	
										}else{
											break;
										}
									}while(true);
									
									do{
										printf("\tUsername Dokter   : ");fflush(stdin);gets(DP.usernameDok);
										if(strlen(DP.usernameDok)==0){
											printf("\t\t[!] Username tidak boleh kosong.\n");
										}else{
											break;
										}
									}while(true);
									
									do{
										printf("\tPassword Dokter   : ");fflush(stdin);gets(DP.passwordDok);
										if(strlen(DP.passwordDok)==0){
											printf("\t\t[!] Password tidak boleh kosong.\n");
										}else{
											break;
										}
									}while(true);
									insertFirstParent(&l, alokasiParent(DP));
									printf("\n\t[*] Berhasil memasukkan data.");
									break;

								case 2:
									if(!isEmpty(l)){
										system("cls");
										printf("\n\tData dokter :");
										printf("\n\t===================================================================");
										printDokter(l);
									}else{
										printf("\t\t\t\t[!] Data dokter masih kosong.");
									}
									break;
								
								case 3:
									if(!isEmpty(l)){
										printf("\t\t\t\tID data yang ingin dicari : ");scanf("%d", &DP.idDokter);
										if(findDokter(l, DP)==NULL){
											printf("\t\t\t\t[!] Data tidak ditemukan.");
										}else{
											system("cls");
											printf("\n\tData dokter dengan ID (%d): ", findDokter(l, DP)->dataParent.idDokter);
											printf("\n\t===================================================================");
											printOne(l, findDokter(l, DP));
										}
									}else{
										printf("\t\t\t\t[!] Data dokter masih kosong.");
									}
									break;
								
								case 4:
									if(!isEmpty(l)){
										printf("\t\t\t\tID data yang ingin diubah : ");scanf("%d", &DP.idDokter);
										if(findDokter(l, DP)==NULL){
											printf("\t\t\t\t[!] Data tidak ditemukan.");
										}else{
											system("cls");
											printf("\n\tMengubah data dokter dengan id (%d): ", findDokter(l, DP)->dataParent.idDokter);
											printf("\n\t===================================================================");
											ubah = findDokter(l, DP);
											do{
												printf("\n\tId Dokter Baru        : ");scanf("%d", &DP.idDokter);
												if(!isUnikParent(l, DP)){
													printf("\t\t[!] ID harus unik.\n");
												}else{
													break;
												}
											}while(true);
											
											do{
												printf("\tNama Dokter Baru      : ");fflush(stdin);gets(DP.namaDokter);
												if(strlen(DP.namaDokter)==0){
													printf("\t\t[!] Nama tidak boleh kosong.\n");
												}else{
													break;
												}
											}while(true);
											
											do{
												printf("\tTanggal Bergabung     : ");fflush(stdin);gets(DP.tanggalBergabung);
												tanggal = atoi(DP.tanggalBergabung);
												bulan = atoi(DP.tanggalBergabung+3);

												if(strlen(DP.tanggalBergabung)!=10){
													printf("\t\t[!] Format Tanggal Salah.\n");
												}else if(DP.tanggalBergabung[2] != '-' || DP.tanggalBergabung[5] != '-'){
													printf("\t\t[!] Format Tanggal Salah.\n");	
												}else if(tanggal > 31 || bulan > 12){
													printf("\t\t[!] Format Tanggal Salah.\n");	
												}else{
													break;
												}
											}while(true);
											
											do{
												printf("\tUsername Dokter Baru  : ");fflush(stdin);gets(DP.usernameDok);
												if(strlen(DP.usernameDok)==0){
													printf("\t\t[!] Username tidak boleh kosong.\n");
												}else{
													break;
												}
											}while(true);
											
											do{
												printf("\tPassword Dokter Baru  : ");fflush(stdin);gets(DP.passwordDok);
												if(strlen(DP.passwordDok)==0){
													printf("\t\t[!] Password tidak boleh kosong.\n");
												}else{
													break;
												}
											}while(true);
											editData(ubah, DP);
											printf("\n\t[*] Berhasil edit data");
										}
									}else{
										printf("\t\t\t\t[!] Data dokter masih kosong.");
									}
									break;

								case 5:
									if(!isEmpty(l)){
										printf("\t\t\t\tID data yang ingin dihapus : ");scanf("%d", &DP.idDokter);
										if(findDokter(l, DP)==NULL){
											printf("\t\t\t\t[!] Data tidak ditemukan.");
										}else{
											deleteAt(&l, findDokter(l, DP));
											printf("\n\t\t\t\t[*] Berhasil menghapus data dan riwayat dokter.");
										}
									}else{
										printf("\t\t\t\t[!] Data dokter masih kosong.");
									}
									break;
									
								case 6:
									goto mDokter;
									break;

								default:
									break;
							}
							getch();
							
						}while(menuAdmin2!=0);
					break;

					case 2 :
						do{
							mAdmin2:
							system("cls");
							red();
							kotak();
							white();
							menuAdmin2 = tampilMenuHewan(menuAdmin2);
							switch (menuAdmin2){
								case 1 :
									if(isEmpty(l)){
										printf("\t\t\t\t[!] Data dokter masih kosong ");
										getch();
										goto mAdmin2;
									}
									system("cls");
									printf("\n\tTambah data Hewan: ");
									printf("\n\t===================================================================");
									printf("\n\t ID Hewan                 : ");scanf("%d", &DH.idHewan);
									do{
										printf("\n\t ID Dokter yang menangani : ");scanf("%d", &DP.idDokter);
										if(findDokter(l, DP)==NULL){
											printf("\t\t[!] ID Dokter tidak ditemukan.");
										}else{
											break;
										}
									}while(true);
									
									if(isFoundHewanID(L, DH.idHewan)==NULL){
										do{
											printf("\n\t -) Nama          : ");fflush(stdin);gets(DH.namaHewan);
											if(strlen(DH.namaHewan)==0){
												printf("\t\t[!] Nama tidak boleh kosong.\n");
											}else{
												break;
											}
										}while(true);

										do{								
											printf("\t    Tanggal Lahir : ");fflush(stdin);gets(DH.tanggalLahir);
											tanggal = atoi(DH.tanggalLahir);
											bulan = atoi(DH.tanggalLahir+3);

											if(strlen(DH.tanggalLahir)!=10){
												printf("\t\t[!] Format Tanggal Salah.\n");
											}else if(DH.tanggalLahir[2] != '-' || DH.tanggalLahir[5] != '-'){
												printf("\t\t[!] Format Tanggal Salah.\n");	
											}else if(tanggal > 31 || bulan > 12){
												printf("\t\t[!] Format Tanggal Salah.\n");	
											}else{
												break;
											}
										}while(true);

										do{
											printf("\t    Jenis Hewan   : ");fflush(stdin);gets(DH.jenisHewan);
											if(strcmpi(DH.jenisHewan, "Anjing")!=0 && strcmpi(DH.jenisHewan, "Kucing")!=0 && strcmpi(DH.jenisHewan, "Burung")!=0){
												printf("\t\t[!] Kami menyediakan layanan hanya untuk Kucing/Anjing/Burung.\n");
											}else{
												break;
											}
										}while(true);

										do{
											printf("\t    Jenis Kelamin : ");fflush(stdin);gets(DH.jenisKelamin);
											if(strcmpi(DH.jenisKelamin, "jantan")!=0 && strcmpi(DH.jenisKelamin, "betina")!=0){
												printf("\t\t[!] Jenis kelamin harus diantara jantan/betina.\n");
											}else{
												break;
											}
										}while(true);
										insertBinatang(&L, DH);
									}
									//set data riwayat yang belum di periksa
									DC.idHewan = DH.idHewan;
									strcpy(DC.obat, "-");
									strcpy(DC.diagnosa, "-");

									do{
										printf("\n\t -) ID Riwayat Periksa : ");scanf("%d", &DC.id_riwayat);
										if(!isUniqueChild(DC.id_riwayat, l)){
											printf("\t\t[!] ID Riwayat harus unik.");
										}else{
											break;
										}
									}while(true);
									
									do{
										printf("\t    Tanggal Periksa    : ");fflush(stdin);gets(DC.tanggal);
										tanggal = atoi(DC.tanggal);
										bulan = atoi(DC.tanggal+3);

										if(strlen(DC.tanggal)!=10){
											printf("\t\t[!] Format Tanggal Salah.\n");
										}else if(DC.tanggal[2] != '-' || DC.tanggal[5] != '-'){
											printf("\t\t[!] Format Tanggal Salah.\n");	
										}else if(tanggal > 31 || bulan > 12){
											printf("\t\t[!] Format Tanggal Salah.\n");	
										}else{
											break;
										}
									}while(true);
									insertFirstChild(l, DP, DC);
									printf("\n\t [!] Berhasil menambahkan data");									
									break;

								case 2:
									printf("\n\t\t\t\tID hewan yang telah mati : ");scanf("%d", &DH.idHewan);
									if(isFoundHewanID(L, DH.idHewan)==NULL){
										printf("\n\t\t\t\t[!] Data hewan tidak ditemukan");
									}else{
										deleteAtHewan(&L, DH.idHewan, &l);
										printf("\n\t\t\t\t[!] Berhasil menghapus data dan riwayatnya");	
									}
									break;

								case 3:
									goto mDokter;
									break;
							}
							getch();
							
						}while(menuAdmin2!=0);
					break;

					case 3:
						if(!isEmptyList(L)){
							system("cls");
							printf("\n\tData semua hewan dan riwayatnya: ");
							printf("\n\t==================================================================================================");
							printAllHewan(l, L);
						}else{
							printf("\n\t\t\t\t[!] Data hewan masih kosong");
						}
						break;

					case 4:
						printf("\n\t\t\t\t[!] Berhasil Logout!");
						getch();
						goto login;

				}
				getch();
			}while(menuAdmin!=0);
				
		}else{
			activeDokter = findUsername(l, username);
			printf("\n\n\t\t\t\t[+] Hello ! Welcome Back, %s.", activeDokter->dataParent.namaDokter);
			getch();
			system("cls");
			do{
				menuDokter:
				system("cls");
				count = 5;
				if(activeDokter->firstChild==NULL){
					count + 2;
				}else{
					count=5;
				}
				printf("\n\tRiwayat Periksa : ");
				printRiwayat(activeDokter, L, &count);
				printf("\n\n\tAntrian Hewan : ");
				printBelumDiag(activeDokter, L, &count);
				menuDokter = tampilMenuDokter (menuDokter, count);
				count=5;
				switch(menuDokter){
					case 1:
						do{
							printf("\n\n\tID Hewan : ");scanf("%d", &DH.idHewan);
							if(isFoundChildInParent(activeDokter, DH.idHewan)==NULL){
								printf("\n\t[!] ID hewan tidak tersedia pada data Anda.");
							}else{
								break;
							}
						}while(true);
						if(strcmp(isFoundChildInParent(activeDokter, DH.idHewan)->dataChild.diagnosa, "-")!=0){
							do{
								printf("\t[!] Hewan telah di diagnosa. Ingin mendiagnosa ulang [iya/tidak] ??");
								printf("\n\t>>> ");fflush(stdin);gets(konfirm);
								if(strcmpi(konfirm, "Tidak")==0){
									goto menuDokter;
								}else if(strcmpi(konfirm, "Iya")==0){
									break;
								}
								printf("\n");
							}while(true);
						}
						DC = isFoundChildInParent(activeDokter, DH.idHewan)->dataChild;
						printf("\n\tDiagnosa : ");fflush(stdin);gets(DC.diagnosa);
						printf("\tObat-obatan : ");fflush(stdin);gets(DC.obat);
						isFoundChildInParent(activeDokter, DH.idHewan)->dataChild = DC;
						printf("\n\t[!] Berhasil mendiagnosa.");
						break;

					case 2:
						printf("\n\tID Dokter : ");scanf("%d", &DP.idDokter);
						if(findDokter(l, DP) == NULL){
							printf("\n\t[!] Data masih kosong");
						}else{
							system("cls");
							printRiwayat(findDokter(l, DP), L, &count);
						}
						count=0;
						break;

					case 3:
						deleteAt(&l, activeDokter);
						printf("\n\t[!] Berhasil resign.");
						getch();
						goto login;
						break;

					case 4:
						getch();
						goto login;
						break;
				}
				getch();
			}while(menuDokter!=0);
		}
	}while(menu!=0);
	;;;;system("pause");
	return 0;
}
