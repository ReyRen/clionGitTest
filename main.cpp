#include <iostream>
#include <string>
#include <complex>
#include <vector>
#include <fstream>
using namespace std;

void bublle_sort(vector<int> &vec, ofstream *ofil = 0) //ofstream这里不能使用引用是因为引用是必须只想一个对象的
{
    for (int ix = 0; ix < vec.size(); ++ix) {
        for (int ij = ix + 1; ij < vec.size(); ++ij) {
            if (vec[ix] > vec[ij])
            {
                if (ofil != 0)
                {
                    (*ofil) << "balabalabala" << endl;
                }
                //swap(vec[ix], vec[ij], ofil);
            }
        }

    }
}

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

    /*
     * 函数的声明不包括函数体
     * 函数的定义包括函数体
     * */

    int ia[8] = {8, 3, 4, 2, 4, 42, 56, 12};
    vector<int> vec(ia, ia + 8);

    bublle_sort(vec);
    bublle_sort(vec, &outfile);

    int ival = 1024;
    int *pi = &ival; /*指针*/
    int &rval= ival; /*引用*/

    int jval = 4096;
    rval = jval; //表示的是改变ival的值，并不是引用指向了新的对象，引用是从一而终的.
    pi = &rval; //这个是将ival（rval所代表的对象）的地址赋值给pi


    int *p2i;
    p2i = new int; //由heap分配出一个类型为int的对象, 再将其地址赋值给Pi.
    p2i = new int(1024); //由heap分配出一个类型为int的对象， 再将其地址赋值给p2i, 并且这个对象的初始值是1024
    int *p3i = new int[24];//p3i初始化为数组的第一个元素的地址. 数组中的每个元素都未经过初始化
    delete(p2i);//释放pi所指的对象
    delete [] p3i;//删除数组中的所有对象

    //seq_array是个数组, 内放函数指针
    /*const vector<int>* (*seq_array[])(int) =
            {
                fibon_seq, lucas_seq, pell_seq
            }*/
    //为了以明确指定方式取用函数指针，我们使用对应的枚举项作为数组索引:
    enum ns_type {
        ns_fibon, ns_lucas, ns_pell
    };


    return 0;
}

void display(const vector<int> &vec)
{
    for (int ix = 0; ix < vec.size(); ix++)
    {
        cout << vec[ix] << ' ' << endl;
    }
}
void display2(const vector<int> *vec)
{
    if(!vec)
    {
        cout << "display():the vector pointer is 0\n";
        return;
    }
    for (int ix = 0; ix < vec->size(); ++ix) {
        cout << (*vec)[ix] << ' ';
    }
    cout << endl;
}

void display(const vector<int> &vec, ostream &os = cout) //默认值的解析操作由最右边开始
/*如果我们为某个参数提供了默认值，那么这个参数右侧的所有参数都必须也具有默认参数值才行*/
{
    for (int ix = 0; ix < vec.size(); ++ix) {
        os << vec[ix] << ' ';
    }
    os << endl;
}
/*
 * 一般情况下函数参数的默认值会防到函数的声明处，也就是在头文件中
 * void display(const vector<int> &, ostream & = cout);
 * 这样在函数定义的时候
 * void display(const vector<int> &vec, ostream &os){}
 * */
void swap(int &val1, int &val2)
{
    int temp = val1;
    val1 = val2;
    val2 = temp;
}

/*const vector<int> *
fibon_seq(int size)
{
    static vector<int> elems; *//*局部静态对象所处的内存空间，即使在不同的函数调用过程中，依然持续存在*//*
    //函数的工作逻辑
    return &elems;
}*/
//使用局部静态对象使我们可以定一个持有Fibonacci数列的vector, 每当调用fibon_seq()时， 我们只需计算那些未被放入elems的元素即可
const vector<int> *
fibon_seq(int size)
{
    const int max_size = 1024;
    static vector<int> elems;

    if (size <=0 || size > max_size)
    {
        cerr << "balabala\n";
        return 0;
    }
    for (int ix = elems.size(); ix < size; ++ix) {
        if (ix == 0 || ix == 1)
        {
            elems.push_back(1);
        }
        else
        {
            elems.push_back(elems[ix - 1] + elems[ix - 2]);
        }
    }
    return &elems;
}
/*
 * inline内联函数目的是为了解决程序中函数调用的效率问题。一般函数进行调用时，要将程序的执行权转到被调用的函数中，
 * 然后再返回到调用它的函数中；而内联函数在进行调用时，是将调用表达式用内联函数体来替换。
 * */

template <typename T>
void display_message(const string &msg,
                        const vector<T> &vec)
{
    cout << msg;
    for (int ix = 0; ix < vec.size(); ++ix) {
        T t = vec[ix];
        cout << t << ' ';
    }
}

//函数指针
bool seq_elem (int pos, int &elem, const vector<int>* (*seq_ptr)(int) = 0)
{
    //调用seq_ptr所指的函数

    const vector<int> *pseq = seq_ptr(pos);

    if (!pseq)
    {
        elem = 0;
        return false;
    }

    elem = (*pseq)[pos - 1];
    return true;
}