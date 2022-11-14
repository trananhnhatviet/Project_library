#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdio>
#include <sstream>
#include <filesystem>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <cstring>
#include <set>
using namespace std;
namespace fs = std::experimental::filesystem;
void Dang_ki();
void Them_sach();
void delete_line(int n);
void Xoa_sach();
void Sua_sach();
void Admin();
void Acc(string user, string ten_dang_nhap);
void Dang_nhap();

int main(){

    Dang_nhap();
    return 0;
}

void Dang_ki() {
    string ten_dang_nhap = "";
    string password = "";
    string user = "";
    ofstream input("User.txt", ios::app);
    ifstream num("Number_User.txt");
    int number_user;
    num >> number_user;
    number_user = number_user + 1;
    num.close();
    ofstream outnum("Number_User.txt");
    outnum << number_user;
    bool check_chua_co = true;
    cout << "Dang ki di bro!!" << endl;
    cout << "Nhap ten dang nhap" << endl;
    cin >> ten_dang_nhap;
    cout << "Password" << endl;
    cin >> password;
    user = ten_dang_nhap + "(abcdefg)" + password + "(hijklmn)";
    if (!input) {
        cout << "No such file found";
    }
    else {
        number_user = number_user + 1;
        input << user << endl;
        input.close();
    }
}
void Them_sach() {
    ofstream output("Book_List.txt", ios::app);
    ofstream output1("ID.txt", ios::app);
    ifstream myfile;
    myfile.open("Number_Book.txt");
    string book = "";
    string author = "";
    string name_of_book = "";
    int number_book;
    int year, num;
    char accept;
    bool check = true;
    while (check == true) {
        myfile >> number_book;
        myfile.open("Number_Book.txt", std::ofstream::out | std::ofstream::trunc);
        myfile.close();
        ofstream outfile("Number_Book.txt");
        cout << "Nhap ten tac gia" << std::flush << endl;
        getline(cin, author);
        fflush(stdin);
        while (author.length() < 30) {
            author = author + ' ';
        }
        author = "                   " + author;
        cout << endl;
        cout << "Nhap ten tac pham " << std::flush << endl;
        fflush(stdin);
        getline(cin, name_of_book);
        while (name_of_book.length() < 40) {
            name_of_book = name_of_book + ' ';
        }
        cout << "So trang" << std::flush << endl;
        cin >> num;
        cout << "Nam xuat ban " << std::flush << endl;
        cin >> year;
        string x = to_string(num);
        while (x.length() < 20) {
            x = x + ' ';
        }
        string t = to_string(year);
        while (t.length() < 20) {
            t = t + ' ';
        }
        number_book = number_book + 1;
        book = author + name_of_book + x + t;
        output << book << endl;
        output1 << number_book << endl;
        outfile << number_book;
        outfile.close();
        cout << "Ban co muon them sach nua khong ? Y/N" << endl;
        cin >> accept;
        cin.ignore();
        if ((accept == 'N') || (accept == 'n')) {
            check = false;
        }
    }
}
void delete_line(int n) {
    int max;
    fstream read_file;
    ifstream input3("Number_Book.txt");
    input3 >> max;
    input3.close();
    ofstream output("Number_Book.txt");
    ofstream output1("ID.txt");
    read_file.open("Book_List.txt");
    if (read_file.fail()) {
        cout << "Error opening file." << endl;
    }
    vector<string> lines;
    string line;
    while (getline(read_file, line))
        lines.push_back(line);
    read_file.close();
    if (n > lines.size())
    {
        cout << "Sach khong co ID " << n - 1;
        cout << " trong thu vien." << endl;
        cout << "Thu vien chi co  " << lines.size() - 1;
        cout << " sach." << endl;
    }
    ofstream write_file;
    write_file.open("Book_List.txt");
    if (write_file.fail())
    {
        cout << "Error opening file." << endl;
    }
    n--;
    for (int i = 0; i < lines.size(); i++)
        if (i != n)
            write_file << lines[i] << endl;
    write_file.close();
    max = max - 1;
    output << max;
    output.close();
    output1 << "ID" << endl;
    for (int i = 1; i <= max; i++) {
        output1 << i << endl;
    }
    output1.close();
}
void Xoa_sach() {
    int line;
    ifstream input("ID.txt");
    ifstream input2("Book_List.txt");
    if ((input2.is_open()) && (input.is_open())) {
        string outfile, outfile2;
        while (getline(input, outfile) && getline(input2, outfile2)) {
            cout << outfile << outfile2 << endl;
        }
    }
    cout << "Ban muon xoa sach nao?" << endl;
    cin >> line; cin.ignore();
    line = line + 1;
    delete_line(line);
}
void Sua_sach() {
    int n, number_book;
    ifstream input1("ID.txt");
    ifstream input2("Book_List.txt");
    ifstream input3("Number_Book.txt");
    input3 >> number_book;
    if ((input2.is_open()) && (input1.is_open())) {
        string outfile1, outfile2;
        while (getline(input1, outfile1) && getline(input2, outfile2)) {
            cout << outfile1 << outfile2 << endl;
        }
    }
    cout << "Ban muon sua sach co ID? " << endl;
    cin >> n; cin.ignore();
    if (n <= number_book) {
        delete_line(n);
        Them_sach();
    }
    else {
        cout << "Khong co sach co ID " << n << " trong thu vien" << endl;
        cout << "Trong thu vien chi co " << number_book << "sach !!!" << endl;
    }

}
void Admin() {
    int n;
    ifstream input("Book_List.txt");
    cout << "Ban la ADMIN!!!" << endl;
    cout << "1. Them sach vao thu vien " << std::flush << endl;
    cout << "2. Sua sach trong thu vien" << std::flush << endl;
    cout << "3. Xoa sach khoi thu vien" << std::flush << endl;
    cin >> n; cin.ignore();
    fflush(stdin);
    if (n == 1) {
        Them_sach();
    }
    if (n == 2) {
        Sua_sach();
    }
    if (n == 3) {
        Xoa_sach();
    }
}
void Acc(string user, string ten_dang_nhap) {
    int n;
    int line_book;
    int numberofbook;
    string user_num_book;
    string user_ID_book;
    ifstream input_book("Book_List.txt");
    ifstream input_ID("ID.txt");
    ifstream input_Number_Book("Number_Book.txt");
    input_Number_Book >> numberofbook;
    user = user + ".txt";
    user_num_book = "num_book_" + user;
    user_ID_book = "ID_book_" + user;
    cout << "Hello my friend " << ten_dang_nhap << endl;
    cout << "Ban muon gi ???" << endl;
    cout << "1. Muon sach" << endl;
    cout << "2. Tra sach" << endl;
    cout << "3. Xoa tai khoan" << endl;
    cout << "4. Exit" << endl;
    cin >> n; cin.ignore();
    if (n == 1) {
        if ((input_ID.is_open()) && (input_book.is_open())) {
            string outfile1, outfile2;
            while (getline(input_ID, outfile1) && getline(input_book, outfile2)) {
                cout << outfile1 << outfile2 << endl;
            }
            input_ID.close();
            input_book.close();
        }
        fstream read_file;
        read_file.open("Book_List.txt");
        if (read_file.fail()) {
            cout << "Error opening file." << endl;
        }
        vector<string> lines;
        string line;
        while (getline(read_file, line))
            lines.push_back(line);
        read_file.close();
        cout << "Ban muon muon sach ID nao?" << endl;
        cin >> line_book; cin.ignore();
        line_book = line_book + 1;
        if (line_book-1 > numberofbook) {
            cout << "Sach khong co ID " << line_book-1;
            cout << " trong thu vien." << endl;
            cout << "Thu vien chi co  " << numberofbook;
            cout << " sach." << endl;
        }
        else {
            ifstream inputnum(user_num_book);
            int num;
            inputnum >> num;
            inputnum.close();
            ofstream input_user(user, ios::app);
            ofstream input_user_ID(user_ID_book, ios::app);
            ofstream input_user_num_book(user_num_book);
            line_book--;
            for (int i = 0; i < lines.size(); i++)
                if (i == line_book)
                    input_user << lines[i] << endl;
            num = num + 1;
            input_user_num_book << num;
            input_user_ID << num << endl;
            input_user.close();
        }
    }
    if (n == 2) {
        int numbook;
        fstream read_file;
        read_file.open(user);
        vector<string> lines;
        string line;
        while (getline(read_file, line))
            lines.push_back(line);
        read_file.close();
        ifstream input1(user_ID_book);
        ifstream input2(user);
        ifstream input3(user_num_book);
        input3 >> numbook;
        input3.close();
        int n;
        if ((input1.is_open()) && (input2.is_open())) {
            string outfile1, outfile2;
            while (getline(input1, outfile1) && getline(input2, outfile2)) {
                cout << outfile1 << outfile2 << endl;
            }
        }
        cout << "Ban muon xoa sach co ID ";
        cin >> n; cin.ignore();
        ofstream write_file;
        ofstream output(user_num_book);
        ofstream output1(user_ID_book);
        write_file.open(user);
        if (write_file.fail())
        {
            cout << "Error opening file." << endl;
        }
        n--;
        for (int i = 0; i < lines.size(); i++)
            if (i != n+1)
                write_file << lines[i] << endl;
        write_file.close();
        numbook = numbook - 1;
        output << numbook;
        output.close();
        output1 << "ID" << endl;
        for (int i = 1; i <= numbook; i++) {
            output1 << i << endl;
        }
        output1.close();
    }
    if (n == 3) {
        remove(user.c_str());
        remove(user_num_book.c_str());
        remove(user_ID_book.c_str());
    }
    if (n == 4) {
        Dang_nhap();
    }
};
void Dang_nhap() {
    ifstream inputabc("Display.txt");
    if (inputabc.is_open()) {
        string outfile1;
        while (getline(inputabc, outfile1)) {
            cout << outfile1 << endl;
        }
        inputabc.close();
    }
    string ten_dang_nhap = "";
    string password = "";
    string user = "";
    int num;
    ifstream input("User.txt");
    ifstream input2("Number_User.txt");
    input2 >> num;
    input2.close();
    bool check_chua_co = true;
    cout << "Dang nhap nao bro" << endl;
    cout << "Nhap ten dang nhap" << endl;
    cin >> ten_dang_nhap;
    cout << "Password" << endl;
    cin >> password;
    user = ten_dang_nhap + "(abcdefg)" + password + "(hijklmn)";
    if (user == "nhatviet(abcdefg)18092004(hijklmn)") {
        Admin();
        check_chua_co = true;
    }
    else { 
        if (num == 0) {
            check_chua_co = false;
            Dang_ki();
        }
        else {
            if (input.is_open()) {
                string outfile;
                while (getline(input, outfile)) {
                    if (outfile != user) {
                        check_chua_co = false;
                    }
                    else {
                        check_chua_co = true;
                    }
                }
            }
            input.close();
            if (check_chua_co == false) {
                Dang_ki();
            }
            else {
                Acc(user, ten_dang_nhap);
            }
        }
    }
}