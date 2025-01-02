#include "final.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<NguoiChet*> res;

void loc_ten(const string& ten) {
    for (auto it = res.begin(); it != res.end(); ++it) {
        if ((*it)->getTen() == ten) {
            delete *it;
            res.erase(it);
            break;
        }
    }
}

void cout_res() {
    string res_cv = "";
    string res_ten;
    float res_sum = 0; int res_die1 = 0;
    int res_years = 0;
    string res_dn = ""; int res_die2 = 0;
    string res_tu_nhan = "";

    for (auto obj : res) {
        if (auto ct = dynamic_cast<chinh_tri_gia*>(obj)) {
            if (ct->getChucVu().length() > res_cv.length()) {
                res_cv = ct->getChucVu();
                res_ten = ct -> getTen();
            }
        } else if (auto dn = dynamic_cast<doanh_nhan*>(obj)) {
            res_sum += dn->getTaiSan();
            if (dn->getTaiSan() > res_die1){
                res_die1 = dn->getTaiSan();
            }

            if (res_die1 > 5){
                res_dn = "nang";
            } else if (res_die1>3 and res_die1<=5){
                res_dn = "binh thuong";
            }
            else {
                res_dn = "nhe";
            }
        } else if (auto tn = dynamic_cast<tu_nhan*>(obj)) {
            res_years += tn->getSoNam();
            if (tn->getSoNam() > res_die2){
                res_die2 = tn->getSoNam();
            }

            if (res_die2 > 20){
                res_tu_nhan = "nang";
            } else if(res_die2 >10 and res_die2 <20) {
                res_tu_nhan = "binh thuong";
            } else {
                res_tu_nhan = "nhe";
            }
        }
    }

    if (!res_cv.empty()) {
        cout << res_ten <<", Chuc vu: " << res_cv << endl;
    }
    if (res_sum > 0) {
        cout << "Doanh nhan: " << res_sum << " ty dong, Cach thuc chet: " << res_dn << endl;
    }
    if (res_years > 0) {
        cout << "Tu nhan: " << res_years << ", Cach thuc chet: " << res_tu_nhan << endl;
    }
}

int main() {
    int m,n;
    cin >> n>>m;

    cin.ignore();
    for (int i = 0; i < n; ++i) {
        int flag;
        cin >> flag;
        cin.ignore();
        string ten, sdt, cach_chet;
        int tuoi;
        cin >> ten >> tuoi >> sdt;

        loc_ten(ten);

        if (flag == 1) {
            string chuc_vu;
            cach_chet = "dau tim";
            cin >> chuc_vu;
            res.push_back(new chinh_tri_gia(ten, tuoi, sdt, cach_chet, chuc_vu));

        } else if (flag == 2) {
            float tai_san;
            cin >> tai_san;
            res.push_back(new doanh_nhan(ten, tuoi, sdt, cach_chet, tai_san));

        } else if (flag == 3) {
            string toi_trang;
            int so_nam;
            cin >> toi_trang >> so_nam;
            res.push_back(new tu_nhan(ten, tuoi, sdt, cach_chet, toi_trang, so_nam));
        }

        if (res.size() > m) {
            delete res[0];
            res.erase(res.begin());
        }
    }

    cout_res();

    


//    for (auto v : res) {
//        v->Xuat();
//        cout << endl;
//    }
//    for (auto v : res) {
//        delete v;
//    }
//    if (res.size() == 0)
//        cout<<"Deathnote trong"<<endl;

    return 0;
}
