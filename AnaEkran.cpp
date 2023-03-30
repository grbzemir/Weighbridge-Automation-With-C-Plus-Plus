#include "AnaEkran.h"

int AnaEkran :: menu()
{
	  int secim;
	  
	  cout<<"\n\tKANTAR OTOMASYONU \n"<< endl;
	  cout<<"\t1- STOK ISLEMLERI "<<endl;
	  cout<<"\t2- SEVKIYAT ISLEMLERI"<<endl;
	  cout<<"\t0- PROGRAMI KAPAT"<<endl;
	  cout<<"\tSeciminiz [0 - 1 - 2] : ";
	  cin>>secim;
	  
	  return secim;	
}

void AnaEkran :: giris()
{
	
	int secim;
	secim=menu();
	
	while(secim !=0)
	{
		switch(secim)
		
		{
			
			case 1:
				stok.giris();
				break;
				
			case 2:
				sevk.giris();
				break;
				
			case 0:
			    break;
			    
			    default :
			    	cout<<"Hatali secim !"<<endl;
			    	break;
			
		}
		
		secim = menu();
		system("cls");
	}
}