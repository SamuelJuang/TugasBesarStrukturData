#include "header.h"

void createEmpty(Multilist *l){
	l->firstParent = NULL;
}

AddressChild alokasiChild(DataC data){
	AddressChild ac;
	ac = (NodeChild*) malloc(sizeof(NodeChild));
	ac->next = NULL;
	ac->dataChild = data;
	return ac;
}

AddressParent alokasiParent(DataP data){

	AddressParent ap;

	ap = (AddressParent) malloc(sizeof(NodeParent));

	ap->next = NULL;
	ap->firstChild = NULL; 
	ap->dataParent = data;

return ap;
}

bool isEmpty(Multilist l){
	return l.firstParent == NULL;
}

bool isUnikParent(Multilist l, DataP DP){
	AddressParent temp= l.firstParent;
	while(temp != NULL){
		if(temp->dataParent.idDokter == DP.idDokter){
			return false;
		}
		temp = temp->next;
	}
	return true;
}

bool isUnikChild(Multilist l, DataC DC){
	AddressParent temp= l.firstParent;
	while(temp != NULL){
        AddressChild c = temp->firstChild;
		while(c != NULL){
            if(c->dataChild.id_riwayat == DC.idHewan){
                return false;
            }
            c = c->next;
        }
		temp = temp->next;
	}
	return true;
}


bool haveChild(AddressParent ap){
	return ap->firstChild != NULL;
}

void insertFirstParent(Multilist *l, AddressParent newNode){
	newNode->next = l->firstParent;
	l->firstParent = newNode;
}

AddressParent findDokter(Multilist L, DataP DP){
	AddressParent p = L.firstParent;
	while(p!=NULL){
		if(p->dataParent.idDokter == DP.idDokter){
			return p;
		}
		p = p->next;
	}
	return p;
} 

void insertFirstChild(Multilist l, DataP idDokter, DataC data){
	AddressParent parent = findDokter(l,idDokter);
	if(parent != NULL){
		AddressChild dataBaru = alokasiChild(data);
		dataBaru->next = parent->firstChild;
		parent->firstChild = dataBaru;
	}
}

void printOne(Multilist l, AddressParent p){
	printf("\n\tID                : %d", p->dataParent.idDokter);
	printf("\n\tNama              : %s", p->dataParent.namaDokter);
	printf("\n\tTanggal Bergabung : %s", p->dataParent.tanggalBergabung);
	printf("\n\tUsername          : %s", p->dataParent.usernameDok);
	printf("\n\tPassword          : %s", p->dataParent.passwordDok);
	printf("\n\t===================================================================");
}

void printDokter(Multilist l){
	AddressParent p=l.firstParent;
	while(p!=NULL){
		printOne(l, p);
		p = p->next;
	}
}

void editData(AddressParent oldNode, DataP DP){
	oldNode->dataParent = DP;
}

void deleteFirst(Multilist *l){
	AddressParent hapus = l->firstParent;
	l->firstParent = l->firstParent->next;
	free(hapus);
}

void deleteAt(Multilist *l, AddressParent hapus){
	if(hapus == l->firstParent){
		deleteFirst(&(*l));
	}else{
		AddressParent before = l->firstParent;
		while(before->next!=hapus){
			before = before->next;
		}
		before->next = hapus->next;
		deleteAllChild(hapus);
		free(hapus);	
	}
	
}

void printHewanRiw(Multilist l, List Hewan, int idHew){
	Address hew =  isFoundHewanID(Hewan,idHew);
	printf("\n\tID Hewan : %d", idHew);
	printf("\n\tNama Hewan : %s", hew->dataHewan.namaHewan);
	printf("\n\tJenis Kelamin : %s", hew->dataHewan.jenisKelamin);
	printf("\n\tJenis Hewan : %s", hew->dataHewan.jenisHewan);
	printf("\n\ttanggal Lahir : %s", hew->dataHewan.tanggalLahir);
	AddressParent ap = l.firstParent;
	if(isFoundChild(l,idHew) == NULL){
		printf("\n\n\tBelum ada data pemeriksaan");
	}else{
		printf("\n\n\tRiwayat : ");
		while(ap != NULL){
			if(isFoundChildInParent(ap,idHew)!= NULL){
				AddressChild c = ap->firstChild;
				printf("\n\tDokter yang memeriksa : %s", ap->dataParent.namaDokter);
				while (c!= NULL){
					if(c->dataChild.idHewan == idHew){
						printf("\n\t-) ID Pemeriksaan : %d", c->dataChild.id_riwayat);
						printf("\n\t   Tanggal pemeriksaan : %s",c->dataChild.tanggal);
						printf("\n\t   Diagnosa : %s", c->dataChild.diagnosa);
						printf("\n\t   Obat : %s", c->dataChild.obat);
					}
					c = c->next;
				}
			}
			ap = ap->next;
		}
	}
	printf("\n\t==================================================================================================");
}

void printAllHewan(Multilist l, List Hewan){
	Address p = Hewan.first;
	while(p!=NULL){
		printHewanRiw(l, Hewan, p->dataHewan.idHewan);
		p = p->next;
	}
}

void printRiwayat(AddressParent ap, List hewan, int *count){
	AddressChild c = ap->firstChild;
	printf("\n\t==================================================================================================");
	while(c!= NULL){
		if(strcmp(c->dataChild.diagnosa,"-") != 0){
			printf("\n\t- ID Riwayat : %d",c->dataChild.id_riwayat);
			printf("\n\t  Diagnosa : %s", c->dataChild.diagnosa);
			printf("\n\t  Obat : %s", c->dataChild.obat);
			printf("\n\t  Tanggal Periksa : %s", c->dataChild.tanggal);
			printf("\n\t  ID Hewan : %d", c->dataChild.idHewan);
			printf("\n\t  Nama Hewan : %s", isFoundHewanID(hewan,c->dataChild.idHewan)->dataHewan.namaHewan);
			printf("\n\t  Jenis Kelamin Hewan : %s", isFoundHewanID(hewan,c->dataChild.idHewan)->dataHewan.jenisKelamin);
			printf("\n\t  Tanggal Lahir : %s",isFoundHewanID(hewan,c->dataChild.idHewan)->dataHewan.tanggalLahir);
			printf("\n\t  Jenis hewan : %s",isFoundHewanID(hewan,c->dataChild.idHewan)->dataHewan.jenisHewan);
			printf("\n\t==================================================================================================");
			*count = *count+10;
		}
		c = c->next;
	}
}

void printBelumDiag(AddressParent ap, List hewan, int *count){
	AddressChild c = ap->firstChild;
	printf("\n\t==================================================================================================");
	while(c!= NULL){
		if(strcmp(c->dataChild.diagnosa,"-") == 0){
			printf("\n\t- ID Riwayat : %d",c->dataChild.id_riwayat);
			printf("\n\t  Tanggal Periksa : %s", c->dataChild.tanggal);
			printf("\n\n\t  ID Hewan : %d", c->dataChild.idHewan);
			printf("\n\t  Nama Hewan : %s", isFoundHewanID(hewan,c->dataChild.idHewan)->dataHewan.namaHewan);
			printf("\n\t  Jenis Kelamin Hewan : %s", isFoundHewanID(hewan,c->dataChild.idHewan)->dataHewan.jenisKelamin);
			printf("\n\t  Tanggal Lahir : %s",isFoundHewanID(hewan,c->dataChild.idHewan)->dataHewan.tanggalLahir);
			printf("\n\t  Jenis hewan : %s",isFoundHewanID(hewan,c->dataChild.idHewan)->dataHewan.jenisHewan);
			printf("\n\t==================================================================================================");
			*count = *count+9;
		}
		c = c->next;
	}
}


AddressChild isFoundChild(Multilist L,int id){
	AddressParent p = L.firstParent;
	while(p !=NULL){
		AddressChild c = p->firstChild;
		while(c !=NULL){
			if(c->dataChild.idHewan == id){
				return c;
			}
			c = c->next;
		}
		p = p->next;
	}
}

AddressChild isFoundChildInParent(AddressParent p,int id){
	AddressChild c = p->firstChild;
	while(c !=NULL){
		if(c->dataChild.idHewan == id){
			return c;
		}
		c = c->next;
	}
	return c;
}

void deleteFirstChild(AddressParent l, int id){
	if(l != NULL){
		if(haveChild(l)){
			AddressChild temp = l->firstChild;
			l->firstChild = l->firstChild->next;
			free(temp);
		}
	}
}

bool isUniqueChild(int id, Multilist l){
	AddressParent AP = l.firstParent;
	while(AP!=NULL){
		AddressChild c = AP->firstChild;
		while(c!=NULL){
			if(c->dataChild.id_riwayat == id){
				return false;
			}
			c = c->next;
		}
		AP = AP->next;
	}
	return true;
}

void deleteAtChild(AddressParent *AP, int id){
	if((*AP)->firstChild!=NULL){
		AddressChild c = (*AP)->firstChild;
		AddressChild first = (*AP)->firstChild;
		AddressChild before = (*AP)->firstChild;
		while(c!=NULL){
			if(c->dataChild.idHewan == id){
				break;
			}
			c = c->next;
		}
		//cari child
		if(c!=NULL){
			if(c == first){
				deleteFirstChild((*AP),id);
			}else{
				while(before->next != c){
					before = before->next;
				}
				before->next = c->next;
				free(c);
			}
		}
	}
}

void deleteAllChild(AddressParent parent){
	AddressChild temp;
	while(haveChild(parent)){	
		temp = parent->firstChild;
		parent->firstChild = parent->firstChild->next;
		free(temp);
	}
}

AddressParent findUsername(Multilist l, string username){
	AddressParent p = l.firstParent;
	while(p!=NULL){
		if(strcmp(p->dataParent.usernameDok, username)==0){
			return p;
		}
		p = p->next;
	}
	return p;
}

AddressParent findDokterNama(string username, Multilist M){
	AddressParent p = M.firstParent;
	while(p!=NULL){
		if(strcmp(p->dataParent.usernameDok,username) == 0){
			return p;
		}
		p = p->next;
	}
	return p;
}
