#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <fstream>
#include <sstream>
#include <ctime>
#include <conio.h>


using namespace std;


char person_now[21];    //储存当前操作的操作者用户名

/***********下面是account类的声明与定义*****************/

class account{
public:
    void create_ac();
    void log_ac();
private:
    string name;
    string password;

};

void account::create_ac(){          //创建账户函数
    cout << " _,  _, _, _ _, _  _, __, _ ___ , _   _, _  _, _, _  _,  _, __, _, _ __, _, _ ___    _, , _  _, ___ __, _, _\n";
    cout << "/ ` / \\ |\\/| |\\/| / \\ | \\ |  |  \\ |   |\\/| /_\\ |\\ | /_\\ / _ |_  |\\/| |_  |\\ |  |    (_  \\ | (_   |  |_  |\\/|\n";
    cout << "\\ , \\ / |  | |  | \\ / |_/ |  |   \\|   |  | | | | \\| | | \\ / |   |  | |   | \\|  |    , )  \\| , )  |  |   |  |\n";
    cout << " ~   ~  ~  ~ ~  ~  ~  ~   ~  ~    )   ~  ~ ~ ~ ~  ~ ~ ~  ~  ~~  ~ ~~~ ~  ~  ~  ~     ~    )  ~   ~  ~~~ ~  ~\n";
    cout << "                                 ~'                                                      ~'\n";
    ofstream accountifile("PersonAc.txt",ios::app);
    if(accountifile.fail()){
        cout<<"Error! Opening file failed."<<endl;
        exit(1);
    }
    accountifile.close();
    account* new_ac = new account();
    string name,pass_w1,pass_w2;
    cout<<"请输入用户名:"<<endl;
    getline(cin,name);
    while(1){
        ifstream infile("PersonAc.txt");
        if (infile.fail()) {
            cout << "Error! Opening file failed." << endl;
            exit(1);
        }
        account tmp_ac;
        bool found = false;
        while (infile>>tmp_ac.name>>tmp_ac.password)
        {
            if (tmp_ac.name == name)
            {
                cout << "用户名已存在，请重新输入用户名: " << endl;
                found = true;
                getline(cin,name);
            }
        }
        infile.close();

        if (!found)
        {
            break;
        }
    }
    new_ac->name = name;
    cout<<"请输入密码:"<<endl;
    cin>>pass_w1;
    cin.ignore();                                        
    cout<<"请再次输入密码:"<<endl;
    cin>>pass_w2;
    cin.ignore();
    while(!(pass_w1==pass_w2)){
        cout<<"两次密码输入不一致，请重新输入:"<<endl;
        getline(cin,pass_w2);                                   
    }
    new_ac->password = pass_w2;
    ofstream accountfile("PersonAc.txt",ios::app);
    if(accountfile.fail()){
        cout<<"Error! Opening file failed."<<endl;
        exit(1);
    }
    accountfile<<new_ac->name<<" "<<new_ac->password<<endl;
    if(accountfile.fail()){
        cout<<"Error! Writing file failed."<<endl;
        exit(1);
    }
    accountfile.close();
    delete new_ac;
    cout<<"创建成功"<<endl;
    cout<<"请选择:   1.返回登录界面   2.退出"<<endl;
    int a;
    cin>>a;
    cin.ignore();
    while(!(a==1||a==2)){
        cout<<"不存在您选择的选项，请重新选择。"<<endl;
        cin>>a;
        cin.ignore();
    }
    if(a==1){
        system("main.exe");
        exit(0);
    }
    else if(a==2){
        exit(0);
    }
    
}

void account::log_ac(){                      //登录账户函数
    cout << " _,  _, _, _ _, _  _, __, _ ___ , _   _, _  _, _, _  _,  _, __, _, _ __, _, _ ___    _, , _  _, ___ __, _, _\n";
    cout << "/ ` / \\ |\\/| |\\/| / \\ | \\ |  |  \\ |   |\\/| /_\\ |\\ | /_\\ / _ |_  |\\/| |_  |\\ |  |    (_  \\ | (_   |  |_  |\\/|\n";
    cout << "\\ , \\ / |  | |  | \\ / |_/ |  |   \\|   |  | | | | \\| | | \\ / |   |  | |   | \\|  |    , )  \\| , )  |  |   |  |\n";
    cout << " ~   ~  ~  ~ ~  ~  ~  ~   ~  ~    )   ~  ~ ~ ~ ~  ~ ~ ~  ~  ~~  ~ ~~~ ~  ~  ~  ~     ~    )  ~   ~  ~~~ ~  ~\n";
    cout << "                                 ~'                                                      ~'\n";
    fstream mm("PersonAc.txt",ios::app|ios::in);
    mm.seekg(0, ios::end);
    if (mm.tellg() == 0)
    {
        cout << "当前暂无账户，请返回注册。" << endl;
        system("pause");
        system("main.exe");
        exit(0);
    }
    mm.seekg(0,ios::beg);
    mm.close();
    string temp_name,temp_password;
    cout<<"请输入用户名:"<<endl;
    getline(cin,temp_name);
    cout<<"请输入密码:"<<endl;
    //getline(cin,temp_password);
    while (1) {                                         
        char ch;
        ch = _getch();
        if (ch == '\r') {
            break;
        }
        if (ch == '\b' && temp_password.length() > 0) {
            temp_password.pop_back();  // 删除字符串的最后一个字符
            cout << "\b \b";
            continue;
        }
        temp_password += ch;  // 将字符添加到字符串的末尾
        cout << "*";
    }
    cout<<endl;
    ifstream infile("PersonAc.txt");
    if (infile.fail()) {
        cout << "Error! Opening file failed." << endl;
        //exit(1);
    }
    account tmp_ac;
    bool found = false;
    while (infile>>tmp_ac.name>>tmp_ac.password)
    {
        if (tmp_ac.name == temp_name && tmp_ac.password == temp_password)
        {
            cout << "登录成功！" << endl;
            found = true;
            strcpy(person_now,temp_name.c_str());
            break;
        }
    }
    infile.close();

    if (!found)
    {
        cout << "账户名或密码错误！" << endl;
        system("pause");
        system("main.exe");
        exit(0);
    }
    


}

/*********************下面是Goods类的声明与定义*****************/

class Goods{
public:
    int serial_num;
    char name[21];
    int num;
    char standardi[21];
    char price[21];

};


/*********************下面是App类的声明与定义*****************/

class App
{
public:

    void Start();
    void log();
    void cre_acc();
    void MainFunc();
    void Input();
    void Sellout();
    void NewAdd();
    void Deletei();
    void Checki();
    void Process_Rec();
    void go_exit();

};

void App::Start(){                      //初始登陆选择界面函数
    //flag = -1;
    system("cls");
    cout<<"* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
    cout<<"*                                                                                                             *"<<endl;
    cout<<"*   *           *    * * * * *   *         *            * * *          * *          *     *      * * * * *    *"<<endl;
    cout<<"*   *     *     *    *           *         *          *             *       *      * *   * *     *            *"<<endl;
    cout<<"*    *   * *   *     * * * * *   *         *         *             *         *    *   * *   *    * * * * *    *"<<endl;
    cout<<"*     * *   * *      *           *         *          *       **    *       *    *     *     *   *            *"<<endl;
    cout<<"*      *     *       * * * * *   * * * *   * * * *      * * *          * *       *           *   * * * * *    *"<<endl;
    cout<<"*                                                                                                             *"<<endl;
    cout<<"*                                                                                                             *"<<endl;
    cout<<"*                                            商品进销存管理系统                                               *"<<endl;
    cout<<"*                                               by 赖彦陶                                                     *"<<endl;
    cout<<"*                                                 请选择:                                                     *"<<endl;
    cout<<"*                                                                                                             *"<<endl;
    cout<<"*                                                1、 登录                                                     *"<<endl;
    cout<<"*                                                2、 注册                                                     *"<<endl;
    cout<<"*                                                0、 退出                                                     *"<<endl;
    cout<<"*                                                                                                             *"<<endl;
    cout<<"* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
    cout<<"您的选择是："<<endl;



}

void App::log(){               //登录函数

    system("cls");
    account temp;
    temp.log_ac();
    
}

void App::cre_acc(){            //注册函数
    system("cls");
    account temp;
    temp.create_ac();

}

void App::MainFunc(){                  //主菜单函数
    system("cls");//当前库存、功能指引
    ofstream kk("GoodsInfo.dat",ios::binary|ios::app);
    kk.close();
    ifstream goodsfile("GoodsInfo.dat",ios::binary);
    if(goodsfile.fail()){
        cout<<"Error! Goodsfile openning failed."<<endl;
        system("pause");
    }
    goodsfile.seekg(0, ios::end);
    if (goodsfile.tellg() == 0)
    {
        cout << "当前暂无商品。" << endl;
        cout<<"****************功能一览****************"<<endl;
        cout<<"1.新增商品     2.删除商品     3.商品进货"<<endl;
        cout<<"4.商品销售     5.盘点商品     6.操作记录"<<endl;
        cout<<"7.退出登录     8.退出程序"<<endl;
        cout<<"您的选择是: ";
    }
    else
    {
        cout<<"当前商品"<<endl;
        goodsfile.seekg(0,ios::beg);
        cout<<setw(18)<<"编号"<<setw(18)<<"名称"<<setw(18)<<"数量"<<setw(18)<<"单位"<<setw(18)<<"价格"<<endl;
        Goods now_goods;
        while(goodsfile.read((char *)&now_goods,sizeof(Goods))){
            cout<<setw(18)<<now_goods.serial_num<<setw(18)<<now_goods.name<<setw(18)<<now_goods.num<<setw(18)<<now_goods.standardi<<setw(18)<<now_goods.price<<endl;
        }
        cout<<"****************功能一览****************"<<endl;
        cout<<"1.新增商品     2.删除商品     3.商品进货"<<endl;
        cout<<"4.商品销售     5.盘点商品     6.操作记录"<<endl;
        cout<<"7.退出登录     8.退出程序"<<endl;
        cout<<"您的选择是: ";
    }
    

}

void App::Input(){                        //进货函数
    cout<<"请输入进货商品编号: ";
    int temp_s_num;
    cin>>temp_s_num;
    cin.ignore();
    ifstream goodsfile("GoodsInfo.dat",ios::binary);
    fstream tempfile;
    tempfile.open("temp.dat",ios::out|ios::binary);
    if(goodsfile.fail()||tempfile.fail()){
        cout<<"Error! !!!!"<<endl;
    }
    ofstream procfile("Process_rec.txt",ios::app);
    if(procfile.fail()){
        cout<<"Error! procfile openning failed."<<endl;
        system("pause");
    }
    time_t now = time(0);
    char* dt = ctime(&now);
    bool found = false;
    Goods tmp_goods;
    while (goodsfile.read((char*)&tmp_goods, sizeof(Goods))) {
        if (tmp_goods.serial_num == temp_s_num) {
            found = true;
            cout<<"请输入进货数量("<<tmp_goods.standardi<<"): ";
            int tempp_num;
            cin>>tempp_num;
            cin.ignore();
            while(tempp_num<=0){
                if(tempp_num==0){
                    cout<<"错误！进货数量输入为零, 请重新输入: ";
                    cin>>tempp_num;
                    cin.ignore();
                }
                else{
                    cout<<"进货数量不可为负数, 请重新输入: ";
                    cin>>tempp_num;
                    cin.ignore();
                }
            }
            procfile<<"进货"<<" "<<tmp_goods.serial_num<<"号 "<<tmp_goods.name<<" "<<tempp_num<<" "<<tmp_goods.standardi<<" "<<tmp_goods.price<<" 操作用户:"<<person_now<<" 操作时间:"<<dt;
            if(procfile.fail()){
                cout<<"Error! procfile writing failed."<<endl;
                system("pause");
            }
            tmp_goods.num+=tempp_num;
        }
        tempfile.write((char*)&tmp_goods, sizeof(Goods)); 
    }
    goodsfile.close();
    tempfile.close();
    if (!found) {
        cout << "查无此商品。" << endl;
        remove("temp.dat");
        system("pause");
        return;
    }
    remove("GoodsInfo.dat");
    if(rename("temp.dat", "GoodsInfo.dat")==0){
        cout<<"进货成功"<<endl;
    }
    procfile.close();
    system("pause");

}

void App::Sellout(){                       //销售函数
    cout<<"请输入销售商品编号: ";
    int temp_s_num;
    cin>>temp_s_num;
    cin.ignore();
    ifstream goodsfile("GoodsInfo.dat",ios::binary);
    fstream tempfile;
    tempfile.open("temp.dat",ios::out|ios::binary);
    if(goodsfile.fail()||tempfile.fail()){
        cout<<"Error! !!!!!"<<endl;
    }
    ofstream procfile("Process_rec.txt",ios::app);
    if(procfile.fail()){
        cout<<"Error! procfile openning failed."<<endl;
        system("pause");
    }
    time_t now = time(0);
    char* dt = ctime(&now);
    bool found = false;
    Goods tmp_goods;
    while (goodsfile.read((char*)&tmp_goods, sizeof(Goods))) {
        if (tmp_goods.serial_num == temp_s_num) {
            found = true;
            cout<<"请输入销售数量("<<tmp_goods.standardi<<"): ";
            int tempp_num;
            cin>>tempp_num;
            cin.ignore();
            while(tempp_num<0||tempp_num>tmp_goods.num){
                if(tempp_num<0){
                    cout<<"销售数量不可为负数，请重新输入: ";
                    cin>>tempp_num;
                    cin.ignore();
                }else if(tempp_num>tmp_goods.num){
                    cout<<"销售数量超过库存量，请重新输入: ";
                    cin>>tempp_num;
                    cin.ignore();                    
                }
            }
            procfile<<"销售"<<" "<<tmp_goods.serial_num<<"号 "<<tmp_goods.name<<" "<<tempp_num<<" "<<tmp_goods.standardi<<" "<<tmp_goods.price<<" 操作用户:"<<person_now<<" 操作时间:"<<dt;
            if(procfile.fail()){
                cout<<"Error! procfile writing failed."<<endl;
                system("pause");
            }
            tmp_goods.num-=tempp_num;
        }
        tempfile.write((char*)&tmp_goods, sizeof(Goods)); 
    }
    goodsfile.close();
    tempfile.close();
    if (!found) {
        cout << "查无此商品。" << endl;
        remove("temp.dat");
        system("pause");
        return;
    }
    remove("GoodsInfo.dat");
    if(rename("temp.dat", "GoodsInfo.dat")==0){
        cout<<"销售成功"<<endl;
    }
    procfile.close();
    system("pause");

}

void App::NewAdd(){                              //添加商品函数
    Goods temp;
    cout<<"请输入商品编号: ";
    cin>>temp.serial_num;
    cin.ignore();
    cout<<"请输入商品名称: ";
    cin.getline(temp.name,21);
    cout<<"请输入商品数量: ";
    cin>>temp.num;
    cin.ignore();
    while(temp.num<0){
        cout<<"错误，商品数量不可为负数！请重新输入数量: ";
        cin>>temp.num;
        cin.ignore();
    }
    cout<<"请输入商品数量单位: ";
    cin.getline(temp.standardi,21);
    cout<<"请输入商品价格: ";
    cin.getline(temp.price,21);
    ofstream goodsfile("GoodsInfo.dat",ios::app|ios::binary);
    if(goodsfile.fail()){
        cout<<"Error! Goodsfile openning failed."<<endl;
        system("pause");
    }
    goodsfile.write((char *)&temp,sizeof(Goods));
    if(goodsfile.fail()){
        cout<<"Error! Goodsfile writing failed."<<endl;
        system("pause");
    }
    goodsfile.close();
    ofstream procfile("Process_rec.txt",ios::app);
    if(procfile.fail()){
        cout<<"Error! procfile openning failed."<<endl;
        system("pause");
    }
    // 获取当前系统日期和时间
    time_t now = time(0);

    // 将 now 转换为字符串形式
    char* dt = ctime(&now);
    procfile<<"添加"<<" "<<temp.serial_num<<"号 "<<temp.name<<" "<<temp.num<<" "<<temp.standardi<<" "<<temp.price<<" 操作用户:"<<person_now<<" 操作时间:"<<dt;
    if(procfile.fail()){
        cout<<"Error! procfile writing failed."<<endl;
        system("pause");
    }
    procfile.close();
}

void App::Deletei(){                        //删除商品函数
    cout<<"请输入需要删除的商品的编号: ";
    int temp_s_num;
    cin>>temp_s_num;
    cin.ignore();
    ifstream goodsfile("GoodsInfo.dat",ios::binary);
    fstream tempfile;
    tempfile.open("temp.dat",ios::out|ios::binary);
    if(goodsfile.fail()||tempfile.fail()){
        cout<<"Error! !!"<<endl;
    }
    ofstream procfile("Process_rec.txt",ios::app);
    if(procfile.fail()){
        cout<<"Error! procfile openning failed."<<endl;
        system("pause");
    }
    // 获取当前系统日期和时间
    time_t now = time(0);

    // 将 now 转换为字符串形式
    char* dt = ctime(&now);
    bool found = false;
    Goods tmp_goods;
    while (goodsfile.read((char*)&tmp_goods, sizeof(Goods))) {
        if (tmp_goods.serial_num == temp_s_num) {
            found = true;
            procfile<<"删除"<<" "<<tmp_goods.serial_num<<"号 "<<tmp_goods.name<<" "<<tmp_goods.num<<" "<<tmp_goods.standardi<<" "<<tmp_goods.price<<" 操作用户:"<<person_now<<" 操作时间:"<<dt;
            if(procfile.fail()){
                cout<<"Error! procfile writing failed."<<endl;
                system("pause");
            }
            continue; // 跳过要删除的记录
        }
        tempfile.write((char*)&tmp_goods, sizeof(Goods)); // 将不需要删除的记录写入输出文件
    }
    goodsfile.close();
    tempfile.close();
    if (!found) {
        cout << "查无此商品。" << endl;
        remove("temp.dat");
        system("pause");
        return;
    }
    remove("GoodsInfo.dat");
    if(rename("temp.dat", "GoodsInfo.dat")==0){
        cout<<"删除成功"<<endl;
    }
    procfile.close();
    system("pause");
}

void App::Checki(){                                      //商品盘点函数
    system("cls");
    ifstream goodsfile("GoodsInfo.dat",ios::binary);
    if(goodsfile.fail()){
        cout<<"Errorrrrr";
    }
    goodsfile.seekg(0, ios::end);
    if (goodsfile.tellg() == 0)
    {
        cout<<"******商品盘点界面******"<<endl;
        cout << "当前暂无商品，请返回进行其他操作。" << endl;
        system("pause");
        return;
    }
    goodsfile.close();
    while(1){
        system("cls");
        ifstream goodsfile("GoodsInfo.dat",ios::binary);
        cout<<"******商品盘点界面******"<<endl;
        cout<<setw(18)<<"编号"<<setw(18)<<"名称"<<setw(18)<<"库存量"<<setw(18)<<"单位"<<endl;
        goodsfile.seekg(0,ios::beg);
        Goods now_goods;
        while(goodsfile.read((char *)&now_goods,sizeof(Goods))){
            cout<<setw(18)<<now_goods.serial_num<<setw(18)<<now_goods.name<<setw(18)<<now_goods.num<<setw(18)<<now_goods.standardi<<endl;
        }
        goodsfile.close();
        cout<<"是否要进行平库操作？(Yes / No)"<<endl;
        cout<<"您的选择是: ";
        string statem;
        cin>>statem;
        while(!(statem=="Yes"||statem=="No")){
            cout<<"\033[91m您输入的选项有误, 请重新输入: \033[0m";
            cin>>statem;
        }
        if(statem == "Yes"){
            cout<<"请选择 \033[91m1.出库  2.入库\033[0m"<<endl;
            cout<<"\033[91m您的选择是: \033[0m";
            int a;
            cin>>a;
            cin.ignore();
            while(!(a==1||a==2)){
                cout<<"\033[91m您输入的选项有误, 请重新输入: \033[0m";
                cin>>a;
                cin.ignore();
            }
            if(a==1){
                cout<<"\033[91m请选择您需要出库的商品编号: \033[0m";
                int bhao;
                cin>>bhao;
                cin.ignore();
                ifstream goodsfile("GoodsInfo.dat",ios::binary);
                fstream tempfile;
                tempfile.open("temp.dat",ios::out|ios::binary);
                if(goodsfile.fail()||tempfile.fail()){
                    cout<<"Error! !!!!!"<<endl;
                }
                ofstream procfile("Process_rec.txt",ios::app);
                if(procfile.fail()){
                    cout<<"Error! procfile openning failed."<<endl;
                    system("pause");
                }
                time_t now = time(0);
                char* dt = ctime(&now);
                bool found = false;
                Goods tmp_goods;
                while (goodsfile.read((char*)&tmp_goods, sizeof(Goods))) {
                    if (tmp_goods.serial_num == bhao) {
                        found = true;
                        cout<<"\033[91m请输入您需要出库的数量("<<tmp_goods.standardi<<"): \033[0m";
                        int tempp_num;
                        cin>>tempp_num;
                        cin.ignore();
                        if(tempp_num<0){
                            cout<<"出库数量不可为负数，请重新输入: ";
                            cin>>tempp_num;
                            cin.ignore();
                        }else if (tempp_num>tmp_goods.num){
                            cout<<"出库数量不可超过库存量，请重新输入: ";
                            cin>>tempp_num;
                            cin.ignore();
                        }
                        procfile<<"\033[91m出库"<<" "<<tmp_goods.serial_num<<"号 "<<tmp_goods.name<<" "<<tempp_num<<" "<<tmp_goods.standardi<<" "<<tmp_goods.price<<" 操作用户:"<<person_now<<" 操作时间:"<<dt<<"\033[0m";
                        if(procfile.fail()){
                            cout<<"Error! procfile writing failed."<<endl;
                            system("pause");
                        }
                        tmp_goods.num-=tempp_num;
                    }
                    tempfile.write((char*)&tmp_goods, sizeof(Goods)); 
                }
                goodsfile.close();
                tempfile.close();
                if (!found) {
                    cout << "\033[91m查无此商品。\033[0m" << endl;
                    remove("temp.dat");
                    system("pause");
                    continue;
                }
                remove("GoodsInfo.dat");
                if(rename("temp.dat", "GoodsInfo.dat")==0){
                    cout<<"\033[91m出库成功\033[0m"<<endl;
                }
                procfile.close();
                system("pause");
            }else if(a==2){
                cout<<"\033[91m请选择您需要入库的商品编号: \033[0m";
                int bhao;
                cin>>bhao;
                cin.ignore();
                ifstream goodsfile("GoodsInfo.dat",ios::binary);
                fstream tempfile;
                tempfile.open("temp.dat",ios::out|ios::binary);
                if(goodsfile.fail()||tempfile.fail()){
                    cout<<"Error! !!!!!"<<endl;
                }
                ofstream procfile("Process_rec.txt",ios::app);
                if(procfile.fail()){
                    cout<<"Error! procfile openning failed."<<endl;
                    system("pause");
                }
                time_t now = time(0);
                char* dt = ctime(&now);
                bool found = false;
                Goods tmp_goods;
                while (goodsfile.read((char*)&tmp_goods, sizeof(Goods))) {
                    if (tmp_goods.serial_num == bhao) {
                        found = true;
                        cout<<"\033[91m请输入您需要入库的数量("<<tmp_goods.standardi<<"): \033[0m";
                        int tempp_num;
                        cin>>tempp_num;
                        if(tempp_num<0){
                            cout<<"入库数量不可为负数，请重新输入: ";
                            cin>>tempp_num;
                            cin.ignore();
                        }
                        procfile<<"\033[91m入库"<<" "<<tmp_goods.serial_num<<"号 "<<tmp_goods.name<<" "<<tempp_num<<" "<<tmp_goods.standardi<<" "<<tmp_goods.price<<" 操作用户:"<<person_now<<" 操作时间:"<<dt<<"\033[0m";
                        if(procfile.fail()){
                            cout<<"Error! procfile writing failed."<<endl;
                            system("pause");
                        }
                        tmp_goods.num+=tempp_num;
                    }
                    tempfile.write((char*)&tmp_goods, sizeof(Goods)); 
                }
                goodsfile.close();
                tempfile.close();
                if (!found) {
                    cout << "\033[91m查无此商品。\033[0m" << endl;
                    remove("temp.dat");
                    system("pause");
                    continue;
                }
                remove("GoodsInfo.dat");
                if(rename("temp.dat", "GoodsInfo.dat")==0){
                    cout<<"\033[91m入库成功\033[0m"<<endl;
                }
                procfile.close();
                system("pause");
            }
        }
        else if(statem == "No"){
            cout<<"是否返回上一界面？(Yes / No)"<<endl;
            string tt;
            cin>>tt;
            while(!(tt=="Yes"||tt=="No")){
            cout<<"您输入的选项有误, 请重新输入: ";
            cin>>tt;
            }
            if(tt=="Yes"){
                return;
            }
        }
    }
}

void App::Process_Rec(){                                  //查看操作记录函数
    system("cls");
    ofstream pp("Process_rec.txt",ios::app);
    pp.close();
    ifstream rec_file("Process_rec.txt");
    if(rec_file.fail()){
        cout<<"Error! Process_rec openning failed.";
    }
    rec_file.seekg(0, ios::end);
    if (rec_file.tellg() == 0)
    {
        cout << "当前暂无操作记录，请返回进行其他操作。" << endl;
        rec_file.seekg(0,ios::beg);
        system("pause");
        return;
    }
    rec_file.seekg(0,ios::beg);
    cout<<"操作记录"<<endl;
    string line;
    while(getline(rec_file,line)){
        cout<<line<<endl;
    }
    rec_file.close();
    system("pause");
}

void App::go_exit(){
    system("main.exe");
    exit(0);
}



/*******************下面是主函数*********************/



int main(){
    App GoodsOperate;
    GoodsOperate.Start();
    int *state = new int;             //选择登录或注册或退出
    cin>>*state;
    cin.ignore();
    while(!(*state==0||*state==1||*state==2)){
        cout<<"您输入的选项不存在，请重新选择: "<<endl;
        cin>>*state;
        cin.ignore();
    }
    if(*state==0){
        exit(0);
    }
    else if(*state==1){
        GoodsOperate.log();
    }
    else if(*state==2){
        GoodsOperate.cre_acc();
    }
    delete state;
    while(1){
        cout.setf(ios::left);
        GoodsOperate.MainFunc();
        int *statei = new int;
        cin>>*statei;                     //选择功能、展示商品信息
        cin.ignore();
        if(!(*statei==1||*statei==2||*statei==3||*statei==4||*statei==5||*statei==6||*statei==7||*statei==8)){
            cout<<"您输入的选项不存在，请重新选择: ";
            cin>>*statei;
            cin.ignore();
        }
        if(*statei==1){
            GoodsOperate.NewAdd();//ok
        }else if(*statei==2){
            GoodsOperate.Deletei();//ok
        }else if(*statei==3){
            GoodsOperate.Input();//ok
        }else if(*statei==4){
            GoodsOperate.Sellout();//ok
        }else if(*statei==5){
            GoodsOperate.Checki();//ok
        }else if(*statei==6){
            GoodsOperate.Process_Rec();//ok
        }else if(*statei==7){
            GoodsOperate.go_exit();//ok
        }else if(*statei==8){
            exit(0);
        }
        delete statei;
    }    
    system("pause");
    return 0;
}















