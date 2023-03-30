#include "Sevkiyat.h"
#include <stddef.h>

Sevkiyat::Sevkiyat()
{

}

Sevkiyat::~Sevkiyat()
{


}

int Sevkiyat::SevkiyatNumarasiUret()
{

    int sayi;
    sayi=0;
    ifstream file("SevkiyatNo.txt");

    while(file.read((char*)&sayi,sizeof(int)) != NULL )
    {

    }
    // kaç byte okuyacağını belirtiyoruz
    sayi++;
    file.close();
    cout<<"Uretilcek numara: "<<sayi<<endl;

    ofstream file2("SevkiyatNo.txt",ios::app);
    file2.write((char*)&sayi,sizeof(int));
    file2.close();
    
   
    return sayi;




}

void  Sevkiyat::aracGiris()

{
    
    cout<<"Arac Girisi Ekrani"<<endl<<endl;
    cout<<"Dolu Giris yapan aracin islemleri"<<endl<<endl;

    t1.numara = SevkiyatNumarasiUret();

    cout<<"Aracin Plakasi: ";
    cin>>t1.plaka;
    cout<<"Aracin Firma Adi: ";
    cin>>t1.firma;
    cout<<"Aracin Urun Adi: ";
    cin>>t1.urun;
    cout<<"Aracin Sofor Adi: ";
    cin>>t1.sofor;
    cout<<"Aracin Tarihi: ";
    cin>>t1.tarih;
    cout<<"Aracin Ilk Tartimi: ";
    cin>>t1.ilkTartim;
    t1.ikinciTartim = 0;
    t1.netTartim = 0;
    t1.durum = 1;
    
     
    ofstream file("Sevkiyat.txt",ios::app);
    
    file.write((char*)&t1,sizeof(Tanimlama));
    file.close();
    cout<<"Arac girisi basarili"<<endl;




}
void  Sevkiyat::aracCikis()
{
     
    
    cout<<"Arac Cikis Ekrani"<<endl<<endl;
    cout<<"Dolu Girip Bekleyen Araclar"<<endl<<endl;
    int i;
    i=0;


    ifstream file("Sevkiyat.txt");
    while(file.read((char*)&t1,sizeof(Tanimlama)) !=NULL )

    {   

        if(t1.durum==1)

        {

        i++;
        cout<<"Aracin Numarasi: "<<t1.numara<<endl;
        cout<<"Aracin Plakasi: "<<t1.plaka<<endl;
        cout<<"Aracin ilk Tartimi: "<<t1.ilkTartim<<endl;


        }
        

    }

    file.close();

    if (i==0)

    {
        system("cls");
        cout<<"Bosaltım Icin Bekleyen Arac Yok:"<<endl;
        
    }

    else

    {   
        int no;
        cout<<i<<" adet arac bekliyor"<<endl;
        
       
        cout<<"Cikis Yapacak Aracin Numarasini Giriniz: ";
        cin>>no;
        int durum2=0;

        ifstream file2("Sevkiyat.txt");

        while(file2.read((char*)&t1,sizeof(Tanimlama)) !=NULL )

       {   

        if(t1.durum==1 && t1.numara == no)

        {

        durum2=1; // aracın numarası doğru girildiğinde durum 1 yapılarak aracın çıkışı yapıldı olarak işaretleniyor
        cout<<"Aracin Numarasi: "<<t1.numara<<endl;
        cout<<"Aracin Plakasi: "<<t1.plaka<<endl;
        cout<<"Aracin ilk Tartimi: "<<t1.ilkTartim<<endl;
        break;


        }

    }

    file.close();

    if (durum2==0)
    {
        cout<<"Hatali Numara Giris ! "<<endl;
        
    }

    else
    {
        cout<<"Aracin ikinci Tartimi(kg): ";
        cin>>t1.ikinciTartim;
        t1.netTartim = t1.ikinciTartim - t1.ilkTartim; // net tartim hesaplanıyor
        
        ifstream file3("Sevkiyat.txt");
        ofstream file4("Sevkiyat4.txt", ios::app);
        
        Tanimlama t2;

        while(file3.read((char*)&t2,sizeof(Tanimlama)) !=NULL )

       {   

        if(t2.durum==1 && t2.numara == no)

        {

        t1.durum=2; // aracın numarası doğru girildiğinde durum 2 yapılarak aracın çıkışı yapıldı olarak işaretleniyor


        }

        file4.write((char*)&t1,sizeof(Tanimlama));

    }

    file3.close();
    file4.close();
    remove("Sevkiyat.txt");
    rename("Sevkiyat4.txt","Sevkiyat.txt");
    cout<<"Arac cikisi basarili"<<endl;
    
        
    }

}

}

void  Sevkiyat::bekleyenAraclar()
{
    
    system("cls");
    cout<<"Arac Cikis Ekrani"<<endl<<endl;
    cout<<"Dolu Girip Bekleyen Araclar"<<endl<<endl;
    int i;
    i=0;


    ifstream file("Sevkiyat.txt");
    while(file.read((char*)&t1,sizeof(Tanimlama)) !=NULL )

    {   

        if(t1.durum==1)

        {

        i++;
        cout<<"Aracin Numarasi: "<<t1.numara<<endl;
        cout<<"Aracin Plakasi: "<<t1.plaka<<endl;
        cout<<"Aracin ilk Tartimi: "<<t1.ilkTartim<<endl;


        }
        

    }

    if (i==0)

    {
        cout<<"Bosaltim Icin Bekleyen Arac Yok:"<<endl;
        
    }

    else

    {
        cout<<i<<" adet arac bekliyor"<<endl;

    }

    file.close();
    

}
void  Sevkiyat::raporlar()
{

    system("cls");
    cout<<"Sevkiyat Rapor Ekrani"<<endl<<endl;
    cout<<"Sevkiyat Rapor islemi"<<endl<<endl;
    int i;
    i=0;

    int toplam;
    toplam=0;
    ifstream file("sevkiyat.txt");
    while(file.read((char*)&t1,sizeof(Tanimlama)) !=NULL )

    {   

        if(t1.durum==2)  // durum = 1 olan boşaltım için bekleyen araçlar duerum =2 boşaltım yapıp çıkan araçlar

        {

        i++;
        cout<<"Aracin Numarasi: "<<t1.numara<<endl;
        cout<<"Aracin Plakasi: "<<t1.plaka<<endl;
        cout<<"Net Tartim: "<<t1.netTartim<<endl;
        toplam = toplam + t1.netTartim; // toplam net tartım hesaplanıyor



        }
        

    }
  
    if (i==0)

    {
        cout<<"Sevkiyata olan Urun Yok:"<<endl;
        
    }

    else

    {
        cout<<endl<<i<<" adet urunh sevkiyati olmustur"<<endl;
        cout<<i<<" Adet Arac Bosaltimi sonucu | Net Toplam Urun "<< toplam << "kg."<<endl;

    }

    file.close();
    


}

int  Sevkiyat::menu()
{

    int secim;
    cout<<"Sevkiyat ISLEMLERI UYGULAMASI"<<endl<<endl; // Işletme otomasyonu uygulaması
    cout<<"[1]-Arac Girisi "<<endl;
    cout<<"[2]-Arac Cikis "<<endl;
    cout<<"[3]-Bekleyen Araclar "<<endl;
    cout<<"[4]-Raporlar "<<endl;
    cout<<"[0]-UstMenuye don "<<endl;
    cout<<"Seciminiz [0-4]: ";
    cin>>secim;
    system("cls");

    return secim;


}


void  Sevkiyat::giris()
{

    int secim;
    secim = menu();

    while( secim !=0 )
    
    {

        switch (secim)
        {
            
        case 1:
        aracGiris();
        break;

        case 2:
        aracCikis();
        break;

        case 3:
        bekleyenAraclar();
        break;

        case 4:
        raporlar();
        break;

        case 0:
        break;

        default:
        cout<<"Yanlis secim yaptiniz"<<endl;
        
        }

        secim = menu();
    }


}

