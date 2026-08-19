/*
    bir array olucak bu arrayın kaç eleman alınacağı yazılacak, 
    bu işlemi kaç gere yapılacağı belirlenilecek döngü için 
    array içindeki elemanlara çift tek kontrolü yapılacak
    eğer array içide tek ve cift elemanlar varsa swap ve bubble kullanarak sıralama yapıcak kücükten büyüğüe
    eğer bir tane cift ve bir tane tek yoksa olduğu gibi print edicez arrayı
*/
#include<iostream>


// my swap func
/*
void mySwap(int &number1,int &number2){
    int temp;
    temp = number1;
    number1 = number2;
    number2 = temp;
}
*/
bool oddControl(int n ,int arry[]){
    bool haveOdd=false;
    bool haveEven=false;
    for(int i=0;i<n;i++){
        if(arry[i]%2==0){
            haveEven=true;
        }
        else{
            haveOdd=true;
        }
    }
    if(haveOdd==true && haveEven==true){
        return true;
    }
    else{
        return false;
    }

}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Geçici diziler 
    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }

    // Bellek sızıntısını önlemek için geçici dizileri sildim
    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right) {
    if (left >= right)
        return;
    
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void bubbleSort(){
    int t;
    int n;
    std::cin>>t;
    for(int i=0;i<t;i++){
        std::cin>>n;
        int myArray[n]={};
        for(int j=0;j<n;j++){
            std::cin>>myArray[j];
        }
        if(oddControl(n,myArray)){
            // bubble sort
            /* bubble sort zaman karmaşıklığının fazla olmasından dolayı site kabul etmedi. 2 saniye 
            her test süresi başına . 5. denemede fazla bir veri denendi ve bubbele sort sıralıyamadı.
            ilk denediğim algoritma buydu. 

            sitenin verdiği kurallar ve değer aralığı:

            Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). The description of the test cases follows.

            The first line of each test case contains a single integer n (1≤n≤2⋅105) — the number of toys.

            The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109) — the integers of the toys.

I           t is guaranteed that the sum of n over all test cases does not exceed 2⋅105

            for(int x = 0; x < n - 1; x++){
                for(int y = 0; y < n - x - 1; y++){
                    if(myArray[y] > myArray[y + 1]){
                        mySwap(myArray[y], myArray[y + 1]);
                    }
                }
            }
            */
            // mergesort 
            mergeSort(myArray, 0, n - 1);
            
        }
        else{
            // pass   
        }
        
        for(int o =0;o<n;o++){
            std::cout << myArray[o] << " ";
        }
        std::cout << std::endl;
    }
    
    
}



int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    bubbleSort();
    
    return 0;
}