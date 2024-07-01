#include <iostream> 
#include <math.h> 

using namespace std; 

int AlgorithmA(int number, int *list);
int NOD(int number_1, int number_2);
int AlgorithmC();
int NOK(int number_1, int number_2);

int AlgorithmA(int number, int *list) { 
    int more=number, i=2, j=0; 
    while (i<=more) { 
        if (number%i==0) { 
            list[j]=i; 
            number/=i; 
            j++; 
        } 
        else i++; 
    } 
    return *list; 
} 

int NOD(int number_1, int number_2) { 
    int nod=1, j, max_number, list1[21], list2[21];  
    AlgorithmA(number_1, list1);
    AlgorithmA(number_2, list2);
    for (j=0; list2[j]!=0; j++) { 
        if (number_1%list2[j]==0 and number_2%list2[j]==0) {
            number_1/=list2[j]; number_2/=list2[j]; nod*=list2[j];
        }
    } 
    for (j=0; list1[j]!=0; j++) {
        if (number_1%list1[j]==0 and number_2%list1[j]==0) {
            number_1/=list1[j]; number_2/=list1[j]; nod*=list1[j];
        }
    }
    return nod; 
}

int AlgorithmC() {
    int number, error=1;
    string enter;
    do {
        try {
            cin>>enter;
            number=stoi(enter);
            if (number<-2000000)
                throw -1;
            error=0;
        }
        catch(...) {
            cout<<"Ошибка ввода: введите числовое значение: ";
        }
    } while(error);
    return number;
}

int NOK(int number_1, int number_2, int *list1, int *list2) {
    int j, nok=1;
    AlgorithmA(number_1, list1);
    AlgorithmA(number_2, list2);
    for (j=0; list2[j]!=0; j++) { 
        if (number_1%list2[j]==0) number_1/=list2[j]; 
        else if (number_1%list2[j]!=0) nok*=list2[j]; 
    } 
    for (j=0; list1[j]!=0; j++) nok*=list1[j]; 
    return nok;    
}

int main() 
{ 
    int numerator, denominator, unit=0, error=1; 
    int numerator_1, denominator_1, numerator_2, denominator_2; 
    char operation=0; 
    do {
        cout<<"Введите первый числитель: "; numerator_1=AlgorithmC();
        cout<<"Введите первый знаменатель: "; denominator_1=AlgorithmC();
        cout<<"Введите второй числитель: "; numerator_2=AlgorithmC();
        cout<<"Введите второй знаменатель: "; denominator_2=AlgorithmC();
        cout<<"Введите действие ('+', '-', '*' или '/'): "; cin>>operation; 
        if (denominator_1==0 or denominator_2==0 or (numerator_2==0 and operation=='/')) {
            cout<<"Перезапустите программу и введите в качестве знаменателя число, отличное от 0, и при делении - числитель второго числа, отличный от нуля.";
        } 
        else error=0;
    }while(error);
    switch (operation) { 
        case '+': { 
            int list1[21], list2[21]; 
            AlgorithmA(denominator_1, list1); 
            AlgorithmA(denominator_2, list2); 
            numerator_1*=denominator_2/NOD(denominator_1, denominator_2);
            numerator_2*=denominator_1/NOD(denominator_1, denominator_2);
            numerator=numerator_1+numerator_2; 
            denominator=NOK(denominator_1, denominator_2, list1, list2); 
            break; 
        } 
        case '-': { 
            int list1[21], list2[21]; 
            AlgorithmA(denominator_1, list1); 
            AlgorithmA(denominator_2, list2); 
            numerator_1*=denominator_2/NOD(denominator_1, denominator_2);
            numerator_2*=denominator_1/NOD(denominator_1, denominator_2);
            numerator=numerator_1-numerator_2; 
            denominator=NOK(denominator_1, denominator_2, list1, list2); 
            break; 
        } 
        case '*': { 
            numerator=numerator_1*numerator_2; 
            denominator=denominator_1*denominator_2; 
            break; 
        } 
        case '/': { 
            numerator=numerator_1*denominator_2; 
            denominator=numerator_2*denominator_1; 
            break; 
        } 
    }
    int new_numenator=numerator;
    if (NOD(numerator, denominator)!=0) numerator/=NOD(numerator, denominator); 
    denominator/=NOD(new_numenator, denominator); 
    if (numerator>=denominator and numerator%denominator!=0) { 
        unit=round(numerator/denominator); 
        numerator=numerator - denominator*unit; 
        cout<<" "<<unit<<"("<<numerator<<"/"<<denominator<<")"; 
    } 
    else if (numerator%denominator==0) cout<<" "<<numerator;
    else cout<<" "<<numerator<<"/"<<denominator; 
    return 0; 
}
