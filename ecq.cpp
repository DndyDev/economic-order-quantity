// Economic order quantity 

/*Входные параметры модели Уилсона
1) v – интенсивность (скорость) потребления запаса, [ед. тов. / ед. t];
2) s – затраты на хранение запаса, [руб./ед.тов.* ед. t];
3) K – затраты на осуществление заказа, включающие оформление и доставку заказа, [руб.];
4) tд – время доставки заказа, [ед.t].

Выходные параметры модели Уилсона
1) Q – размер заказа, [ед. тов.];
2) L – общие затраты на управление запасами в единицу времени, [руб./ед.t];
3) 𝜏 – период поставки, т.е. время между подачами заказа или между поставками, [ед.t];
4) tзак – точка заказа, т.е. размер запаса на складе, при котором надо подавать заказ на доставку очередной партии, [ед. тов.].
*/
#include <iostream>
#include <string>

using namespace std;

void ecq_opt(int item_count, int procent){
    
}
void ecq (int velocity, int holding_cost, int order_cost,int delivery_time, int item_cost, int time){
    double quantity = abs( 2 * velocity * holding_cost / order_cost ); // количество
    double limit_cost = order_cost * velocity * time / quantity 
                    + holding_cost * time * quantity  / 2 
                    + item_cost * velocity * time;
    double consingment = delivery_time * velocity; //  партия – t зак
    double period_consigment = quantity / velocity; //  𝜏 – период поставки
    double frequency = velocity / quantity; // частота 
    double consingment_count = velocity * time / quantity;



    /* ToDo :  
        * Подписи к переменным.
        * Таблица
    */
    cout << " " <<  quantity << "\n";
    cout << limit_cost << "\n";
    cout << consingment << "\n";
    cout << period_consigment << "\n";
    cout << frequency << "\n";
    cout << consingment_count << "\n";

}




int main()
{
    int p = 3.8 * 1000; //  rub 
    int q = 190; // count
    int E = 6; // procent
    int W = 40; // kg
    int D = 20 * 1000 / 40  / 12; // box in day
    int C = 20 * 1000; //  rub
    int t = 3; // day
    int S = 120; // rub/day
    int A = 6500 / 12; // rub/day

    int kvartal  = 3;

    string answer;

    cout << "Need permanent rental ? y/n" << endl;
    cin >> answer;
    if (answer == "y"){
        ecq(D, D/W * A ,p,t,p,kvartal);
    }else{
        ecq(D,S,p,t,p,kvartal);
    }
}   