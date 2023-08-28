#include "header.h"

void createEmptyList(List *L){
    L->first = NULL;
}

bool isEmptyList(List L){
    return L.first == NULL;
}

Address alokasi(DataH data){
    Address p = (Node*) malloc(sizeof(Node));
    p->dataHewan = data;
    p->next = NULL;
    return p;
}

void insertFirstList(List *L, Address newNode){
	newNode->next = (*L).first;
	(*L).first = newNode;
}
void insertLastList(List *L, Address newNode){
	Address P;
	if(isEmptyList(*L)){
		insertFirstList(L,newNode);
	}else{
		for(P=(*L).first;P->next !=NULL;P=P->next);
		P->next = newNode;
	}
}

void insertAfter(Address before, Address newNode){
	if(before!=NULL){
		newNode->next  = before->next;
		before->next = newNode;
	}
}

Address findLastAnjing(List l){
	Address p = l.first;
	if(isEmptyList(l)){
	
	}else{
		while(strcmpi(p->dataHewan.jenisHewan,"anjing" )!= 0 && p!= NULL){
			if(strcmpi(p->next->dataHewan.jenisHewan,"anjing")== 0){
				p = p->next;
			}else{
				return p;
			}
			p = p->next;
		}
	}
	return p;
}

Address findLastBurung(List l){
	Address p = findLastAnjing(l);
	if(isEmptyList(l)){
	
	}else{
		while(strcmpi(p->dataHewan.jenisHewan,"burung" )!= 0 && p->next!= NULL){
			if(strcmpi(p->next->dataHewan.jenisHewan,"burung")== 0 ){
				p = p->next;
			}else{
				return p;
			}
		
		p = p->next;
		}
	}
	return p;
}

void insertBinatang(List *L,DataH hewan){
	string jenis;
	strcpy(jenis,hewan.jenisHewan);
	if(strcmpi(jenis,"anjing") == 0){
		insertFirstList(&(*L),alokasi(hewan));
	}else if (strcmpi(jenis,"burung") == 0){
		if(isEmptyList(*L)){
			insertFirstList(&(*L),alokasi(hewan));
		}else if(strcmpi((*L).first->dataHewan.jenisHewan, "anjing") != 0){
			insertFirstList(&(*L),alokasi(hewan));
		}else{
			insertAfter(findLastAnjing(*L),alokasi(hewan));
		}
	}else if(strcmpi(jenis,"kucing") == 0){
		if(isEmptyList(*L)){
			insertFirstList(&(*L),alokasi(hewan));
		}else{
			insertAfter(findLastBurung(*L),alokasi(hewan));
		}
	}
}
void deleteFirstHewan(List *L){
	if(!isEmptyList((*L))){
		Address del = (*L).first;
		(*L).first = (*L).first->next;
		free(del);
	}
}

void deleteAtHewan(List *L, int id, Multilist *M){
	Address P;
	Address del = isFoundHewanID((*L), id);
	if(!isEmptyList((*L))){
		if((*L).first->dataHewan.idHewan == id){
			deleteFirstHewan(&(*L));
		}else{
			P=(*L).first;
			while(P->next !=  del){
				P = P->next;
			}
			P->next = del->next;
			free(del);
		}
		//menghapus semua data binatang yang di riwayat
		 AddressParent ap = (*M).firstParent;
		 while(ap!=NULL){
		 	while(isFoundChildInParent(ap, id) != NULL){
		 		deleteAtChild(&ap,id);
		 	}
		 	ap = ap->next;
		 }
	}
}

void printHewan(List L){
	Address p = L.first;
	while(p!=NULL){
		printf("\n\tID            : %d", p->dataHewan.idHewan);
		printf("\n\tNama          : %s", p->dataHewan.namaHewan);
		printf("\n\tTanggal Lahir : %s", p->dataHewan.tanggalLahir);
		printf("\n\tJenis Hewan   : %s", p->dataHewan.jenisHewan);
		printf("\n\tJenis Kelamin : %s", p->dataHewan.jenisKelamin);
		p = p->next;
	}
}

Address isFoundHewanID(List L, int id){
	Address p = L.first;
	while(p!=NULL){
		if(p->dataHewan.idHewan == id){
			return p;
		}
		p = p->next;
	}
	return p;
}
