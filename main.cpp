#include <iostream>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <vector>
#include <list>
#include <unordered_set>


void print (std::pair<int, std::string> a)
{
    std::cout << a.first <<std::endl;
}

void print2 (std::list<int> a)
{

}

int main ()
{

    std::unordered_multimap<int, std::string> arr;
    std::string str;

    int z = 5;

    for (int i = 0; i < z ; ++i)
    {
        std::cout << "введите значение : \n";
        std::getline(std::cin, str);
        arr.emplace(i,str);

        std::cout << i << " = " << str << std::endl;
    }

    std::cout << "\n";

    std::cout<< "поместите 2 новых значения в ключ 4 \n"<<std::endl;
    for (int i = 0; i < 2; ++i)
    {
        std::cout << "введите значение : \n";
        std::getline(std::cin, str);
        arr.insert(make_pair(4,str));
    }

    std::cout << "\n";

   std::cout<< "удаление значения ключа 2"<<std::endl;
    arr.erase(2);


    std::cout<< "вывод multimap :"<<std::endl;
    std::for_each(arr.begin(),arr.end(), print);

    std::cout << "\n";


    std::map<int, std::string> arr2;
    arr2.insert(arr.begin(),arr.end());

    std::cout<< "вывод map :"<<std::endl;
    std::for_each(arr2.begin(),arr2.end(), print);

//№2


    int s = std::count_if(arr2.begin(),arr2.end(), [](std::pair<int, std::string> a){return a.first >= 0;});
    std::cout<<"число элементов,имеющие положительные ключи : "<< s << std::endl<< std::endl;


    std::vector<int> vec (arr2.size());
    std::transform(arr2.begin(), arr2.end(),vec.begin(),[](std::pair<const int, std::string> a){return a.first;});
    std::cout<<"вектор из ключей = ";
    std::for_each(vec.begin(),vec.end(),[](int a) {std::cout<< a << " ";});

    std::cout << "\n\n";

//№3

    auto it = std::find(vec.begin(),vec.end(), 1);
    std::cout << "позиция элемента 1 = " <<it-vec.begin()<<std::endl ;


    std::sort(vec.begin(),vec.end());
    std::cout << "отсортированные элементы вектора по возрастанию : "<<std::endl;
    std::for_each(vec.begin(),vec.end(),[](int a) {std::cout<< a << " ";});

    std::cout << "\n\n";

    std::list<int> list;
    list.assign(vec.begin(),vec.end());
    std::cout << "скопированные значения в список элементов : "<<std::endl;
    for_each(list.begin(),list.end(),[](int a){std::cout<< a << " ";});

    std::cout << "\n\n";


//№4

    std::replace_if(list.begin(),list.end(), [](int a){ return a<0 ;}, 0 );
    std::cout << "замена отрицательных значений на 0 : "<<std::endl;
    for_each(list.begin(),list.end(),[](int a){std::cout<< a << " ";});

    std::cout << "\n\n";

    list.sort(std::greater<int>());
    std::cout << "сортировка элементов по убыванию : "<<std::endl;
    for_each(list.begin(),list.end(),[](int a){std::cout<< a << " ";});

    std::cout << "\n\n";

    std::unordered_set<int> set_s;

    set_s.insert(list.begin(),list.end());
    std::cout << "скопрированные значения list в stl : "<<std::endl;
    for_each(set_s.begin(),set_s.end(),[](int a){std::cout<< a << " ";});

    std::cout << "\n\n";

//№5

std::cout << "поиск элемента = 5 :"<<std::endl;
std::find(set_s.begin(),set_s.end(), 5 );

    if(std::find(set_s.begin(),set_s.end(), 5 )!= set_s.end())
    {
    std::cout<<"элемент = 5 найден"<<std::endl;
    }

    else
    {
    std::cout<<"элемент = 5 не найден"<<std::endl;
    }

}




