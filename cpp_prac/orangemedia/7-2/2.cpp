//IS-A 관계의 상속, 소멸자 빼먹지 않기
#include <iostream>
#include <cstring>
using namespace std;

class Book{
private:
    char *title;
    char *isbn;
    int price;
public:
    Book(char *_title, char *_isbn, int _price): price(_price){
        title = new char[strlen(_title)+1];
        isbn = new char[strlen(_isbn)+1];
        strcpy(title, _title);
        strcpy(isbn, _isbn);
    }
    void showBookInfo(){
        cout<<"제목: "<<title<<endl;
        cout<<"ISBN: "<<isbn<<endl;
        cout<<"가격: "<<price<<endl;
    }
    ~Book(){
        delete []title;
        delete []isbn;
    }
};

class Ebook: public Book{
private:
    char *DRMKey;
public:
    Ebook(char *_title, char *_isbn, int _price, char *_DRMKey): Book(_title, _isbn, _price){
        DRMKey = new char[strlen(_DRMKey)+1];
        strcpy(DRMKey, _DRMKey);
    }
    void showEbookInfo(){
        showBookInfo();
        cout<<"인증키: "<<DRMKey<<endl;
    }
    ~Ebook(){
        delete []DRMKey;
    }
    
};

int main() {
    Book book("좋은 C++", "555-12345-890-0",  20000);
    book.showBookInfo();
    cout<<endl;
    Ebook ebook("좋은 C++ ebook", "555-12345-890-1", 10000, "sf4e8sf46sfs85");
    ebook.showEbookInfo();
    return 0;
}