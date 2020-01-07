#include <iostream>
#include <string>
#include <complex>
#include <vector>
#include <fstream>
using namespace std;

int main() {
    string user_name;
    int user_val; // 回答次数
    int num_right;
    int num_tries(0); // 构造函数语法进行初始化
    // complex<double> purei(0, 7) complex是一个模板类(可以在使用时再决定使用的数据类型)
    double usr_score = 0.0;
    char usr_more;
    cout << "Try another sequence? Y/N";
    cin >> usr_more;
    bool go_for_it = true;
    const int max_tries = 3;
    const int seq_size = 18;
    int pell_seq[seq_size];
//    vector<int> pell_seq(seq_size);
//    pell_seq[0] = 1;
    // 使用已初始化的array作为vector的初值
    int elem_vals[seq_size] {
        1, 2, 3, 4, 5, 6, 7, 8, 9,
        10, 11, 12, 13, 14, 15, 16, 17, 18
    };
    vector<int> elem_seq(elem_vals, elem_vals + seq_size);
    /*
     * variable-sized object may not be initialized
     * C99不是规定可以用变量定义数组的大小，但是定义了之后初始化会报错？
     * 那是因为在数组初始化时，在编译时已经确定了，但是变量在编译时是不确定的
     * 只有在运行时才能确定. 所以说怎么能把一个确定的量初始化给一个不确定的量呢>
     */
    vector<int> fibonacci;
    vector<int> *pv = 0;
    pv = &fibonacci;

    // 以输出模式开启seq_data.txt
    //ofstream outfile("seq_data.txt");//文件中原有的数据会被丢弃
    ofstream outfile("seq_data.txt", ios_base::app); // append模式
    if (!outfile) {
        cerr << "Oops!! Unable to save session data!!\n";
    } else {
        // ok: outfile开启成功, 接下来将数据写入
        outfile << user_name << ' '
                << num_tries << ' '
                << num_right << endl; // endl会插入一个换行符, 并清除output buffer的内容.
    }
    // 打开一个可供读取的文件ifstream(供输入的file stream)
    ifstream infile("seq_data.txt");
    string name;
    string usr_name;
    int nt;
    int nc;
    while (infile >> name) // anna 24 19
    {
        infile >> nt >> nc;
        if (name == usr_name)
        {
            cout << "Welcome back, " << usr_name
                 << "\nYour current score is " << nc
                 << " out of " << nt << "\nGood Luck!\n";
        }
    }
    /*
     * 同时想要读取和写入一个文件
     * */
    fstream iofile("seq_data.txt",
                    ios_base::in | ios_base::app);
    if (!iofile)
    {
        // Oops
    } else
    {
        // 开始读取之前， 将文件重新定位至启示位置
        iofile.seekg(0);
    }

    return 0;
}