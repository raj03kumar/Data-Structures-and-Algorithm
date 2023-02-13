# Data-Structures-and-Algorithm
This repository consists of most important questions of related to array, searching, sorting, linked list, stack, queues, binary tree, binary search tree, recursion, backtracking, heaps, hashing and greedy algorithms

You will soon get graph and dp related questions.

# Rules: 
```
Use # rarely #### for sub-topics and ### for new topic.

```cpp for better formating of code and dont forget to align your code.
```

-------------------------------------------------------
### DATA STRUCTURES AND ALGORITHMS BEGIN

```
OPERATORS: 
Left shift operator:
4<<1
(0100)-->(1000) i.e. 4 becomes 8
a<<n        -->a*2^n;
Right shift operator:
4>>1
(0100)-->(0010) i.e. 4 becomes 2
a>>n        -->a/2^n;
int great=max(a,max(b,c));
```

#### TO REVERSE A STRING:

```c++
int main(){
    string a;
    cin>>a;
    string ans;
    for(int i=a.length()-1; i>=0;i--){
        ans+=a.substr(i,1);
    }
    cout<<ans;
    return 0;
}

USING RECURSION:
void reverse(string a){
    if(a.length()==0){
        return ;
    }
    reverse(a.substr(1));
    cout<<a[0];
}

int main(){
    reverse("raj");
    return 0;
}
```
  
#### CONVERSION OF BINARY TO DECIMAL AND VICE-VERSA IN C++

1. Using SToI(string to integer function)
```cpp
int main(){
    //binary to decimal
    string a="1111111101010101010101010110011";
    int dec=stoi(a,nullptr, 2); //or int dec=stoi(a,0,2);
    /*
    if we change the base of the given string from 2 to 10 then 
    it will return same string, 
    if 16 then it understands the input string as hexadecimal 
    number and converts hexadecimal to integer.
    */
    cout<<dec;
    return 0;
}
or
int main(){
    string a="111111110101010101010101011111111111111111111111110011";
    long long dec=stoll(a,0, 2);
    cout<<dec;
    return 0;
}
```

2. Using bitset
```cpp
int binaryToDecimal(string s)
{
    bitset<64> bits(s);
    int number = bits.to_ulong();
    return number;
}
```
#### BASIC SORTING ALGORITHMS:
```
SELECTION SORT:find the minimum element in unsorted array and swap it with the element in the beginning.
i loop from 0 to n-1 
j loop from i+1 to n
//implement selection sort on your own.
--> in selection sort the first half of the array becomes sorted as intermediate result
--> in bubble sort the second half of the array becomes sorted as intermediate result.
```
```
BUBBLE SORT: repeatedly swap 2 adjacent elements if they are out of order. 
It is called bubble sort because the largest element comes out first like a bubble. 
here we make int counter=1; while loop till counter<n and for loop till n-counter.
```
```
INSERTION SORT: insert an element from unsorted array to its correct position 
in sorted array. And the first element is considered to be the sorted array. 
Then we check it with the just next element. and so on. 
if we find any element greater then we put it in its correct place in the sorted array.
first for loop and then while iteration because we have to shift all the elements.
(while is a type of recursion). 
this is easy but remember it.
```

## GOOD ALGORITHMS:
```
Q. Max element till i in an array: o(n) traverse the array and store the maximum till that number.
-> Number of subarray in an array of n elements is = nC2 + n =n*(n+1)/2
subsequences of array: means numbers of array in same order of index but any index can be missed, 
but the main point is the order of index always remains same. 
12345 is the array then 245 can be a subsequence.
number of subsequence in an array of n elemnts in 2^n.
```
```
Q. Sum of all subarrays: O(n^2) using i and j loops. But it can be done in O(n) see g4g.
```
```
Q. Longest arithemetic subarray: see good algos.
```
```
Q. record breaker: see good algos. lecture 8.4
```
```
Q. TO FIND THE INDEX OF FIRST REPEATING ELEMENT IN AN ARRAY? 
lecture 8.5: see good algos.
approach is like count sort;    
NOTE: WE CAN'T DECLARE AN ARRAY OF LENGHT 10^6 inside main function. 
We can do this outside main function because 
the memory allocated to main funtion is limited.
IN ANY QUESTION IF WE HAVE TO FIND MAX OR MIN, THEN WE HAVE TO MAKE 
ELEMENTS TO STORE THE MIN AND THEN ANOTHER 
VARIABLE TO STORE CURRENT AND CHANGE BY min or max FUNCTION IN ELSE CASE OF IF-ELSE.
```
```
Q. Subarray with given sum? : see good algos. here we have to do 2 pointer approach. 
we have to maintain two pointers at the start and see if the given sum is less than the current 
sum by iterating through the elemnts. if it is greater then we move the other pointer so the sum 
is in our desired limit. O(n)
```
```
Q. smallest positive missing number? we make a boolean array just like count sort and mark true 
for all the elements present in the array. we iterate and find the first false element. O(n)
```
```
Q. to print all the subarray of a set? O(n^3) using i, j and k loops. easy hai.
```
```
Q. maximum subarray sum? KADANE'S ALGORITHM. O(n).
```
```
Q. ciruclarMaxSubArray? here we define contributing and non-contributing terms. 
and max sum will be total sum - noncontributingSum. and to find the noncontibuting elements,
we reverse the sign of the arrayelements and run kadane's algorithm.
```
```
Q. Pair sum problem? Lecture 8.6 Here we are given a sorted array and we have to find continous 
element who's sum is equal to the given sum. So here we make two pointer approach. 
in this we make a low pointer and a high pointer if the sum of both the element is less 
than the sum then we move the low pointer to increase the current sum else to decrease the 
current sum we move the high pointer towrds left.
```
7 QUESTIONS in good algo are very good and must try.

2D ARRAY IS VERY EASY. Searching, Spiral order print, 
Matrix transpose(very easy), Matrix multiplication, 2D matrix search(boring)--> these in lecture 9.2 

Character arrays: Character arrays are array of characters with null at last. They are exactly like 
strings. (NOT IN USE)
```cpp
//To get input of a sentence in cpp:
int main(){
    string a;   //better use string instead of char array.
    // cin>>a;
    getline(cin, a);    //to get input of a sentence in cpp.
    cout<<a;
    return 0;
}
```
```cpp
POINTERS: simply declaring pointer int *ptr;
ptr=&a;
cout<<ptr; //will give the address of a
//and *ptr will give the value of a. 
//you already know it Raj.
/* NOTE: If we are making function especially void then it is sure that we want changes 
in our original data. so we pass value by reference and that is by simply adding & and 
nothing more, no * nothing. it is old method.
*/
void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}

int main(){
    int a=11;
    int b=15;
    swap(a,b);
    cout<<a<<"\n";
    cout<<b<<"\n";
    return 0;
}
```
```
PASSING POINTERS TO FUNCTION: we write *a,*b in the function, and when we r calling 
then we send swap(&a,&b)
STACK VS HEAP: if we are storing memory dynamically by making a pointer then it
gets stored in heap and act as a global variable. So we have to deallocate the memory also

similar to java use cpp. 
```
```cpp
int *p = new int(); //to dynamically allocate memeory in heap.
cin>>p;
delete(p);
//here p is in stack but it is pointing to heap.
int p= new int[n]; //to dynamically allocate memory in heap.
delete[]p;
p=NULL; //to point p to NULL.
```
```
when we exit our main function then p also gets destroyed.
Memory leak is the situation when we allocate the memory in heap and don't delete it.
it is an serious issue. No issue for computers as because when the program gets terminated 
then everything gets deleted but for web servers were it is always on there it is a serious issue.
```

#### STRINGS:
```cpp
string str;
getLine(cin,str);// to get complete sentence as input.
s1+s2 to concatenate
s1.sppend(s2) to append s2 at last of s1. but here s1 changes.
s1.compare(s1) compares the strings in dictionary order.
s1.find("something")--> to find if 
sort(s.begin(), s.end())--> to sort a string.

TO SORT AN STRING INTO DECREASING order

sort(s.begin(), s.end(), greater<int>());
transform(some parameters) is used to transform complete string to uppercase or to lowercase.
transform(s.begin(), s.end(), s.begin(), ::toupper)
transform(s.begin(), s.end(), s.begin(), ::tolower)
```
### BIT MANIPULATION: easy simple common sense hai.
```
1<<n == 2^n. you know this is left set bit. />/STRIVER ZINDABAD. 
this means that you shift 1 by n bits left side.
since, a<<n        -->a*2^n;
```
```cpp
1. getBit: we need to get bit of a given position i say i=2.
we use left shift operator at i. i=0010.
and indexing of the numbers start from back side. i.e here n=0101 so indexing goes:
0101 ->n.
3210 ->indexes.
so 1<<i=0100.
//learn better from video or practice on paper.

1. get bit: we do and operation with 2 exp i or 1<<i and do and operation. if the result is 0, then the 
bit is not set. else the bit is set.
2. set bit: we follow the above process but we do or operation.
3. clear bit: we create same thing but we use negation of 2 exp i or the mask. and we do and operation, 
so that the other bits are not disturbed.
4. clear last bit: we simply do n&(n-1). simple logic think yourself.
5. update bit: FALTU HAI YE SIMPLE BILKUL. first clear the bit then do left shift of the value. and or 
operation because we want to set.
different analogy is if the value is 0 then clear the bit at that position, if value is one then set 
the bit to that position.

int getBit(int n, int pos){
    return ((n&(1<<pos))!=0);
}
int setBit(int n, int pos){
    return (n|(1<<pos));
}
int clearBit(int n, int pos){
    int mask= ~(1<<pos);
    return (n&mask);
}
int updateBit(int n,int pos, int value){
    int mask= ~(1<<pos);
    n = n & mask;
    return n|(value<<pos)
}
```
```cpp
Q. to find if a number is power of 2. n&(n-1)==0;
//these are the funtions of bit manipulation.
Q. count the number of set bits in a number?--> good algo 8
while(n!=0){
    we set the clear the last bit;
    counter++;
} time complexity is number of set bits.

Q. to find the last set bit of a number?
count = 0;
while(xor){
    if(xor&1){
        break;
    }
    count++;
    xor=xor>>1;
}

NOTE: XOR of all the subsets is always zero unless there is only 1 element then it is 1.
```
```
POWER SET ALGORITHM FOR GENERATING ALL THE SUBSETS OF A GIVEN SET?--> good algo 9
same as digital system analogy.
practice some easy bit manipulation questions in lecture 14.3 Q1, to find the unique elemnt in array, Q2. find 2 unique element in an array. Q3. if all numbers are repeated 3 times then find the elemnt which is repeated 2 times.
```
```
Seive of Eratosthenes: u know it.       and to find the prime factors of a number using seive.
INCLUSION AND EXCLUSION PRINCIPLE: it is same as set which we studied in class 11. Q. check how many numbers between 1 and 100 are divisible by 5 or 7? Ans: numbers divisible by 5 + numbers divisible by 7 - numbers divisible by 35.
```
```cpp
Euclid algo to find gcd: it is the same gcd finding thing. remember if we subtract two numbers then their gcd doesn't change.
int gcd(int a, int b){
    while(b!=0){
        int rem=a%b;
        a=b;
        b=rem;
    }
    return a;
}

NOTE: If we have to pass vectors in functions then passing the reference to vector is good practice and consumes less time complexity.

To calculate the range of data types: int -> 4 bytes means 32 bits. one bit can store 0 or 1 so 32 bits can store 2^32 so 2^31 negative integers and 2^31 postivite integers are stored.
do{

}while();

switch(a){          //a can be int or char
    case 1:
        break;
    case 2:
        break;
}
#define n 100
#define ll long long
// means we are defining value of n as 100 throughout the program.;
```

#### -----------RECURSION------------
```
NOTE: better go with void in recursion data type. or create a temporary variable or static variable to store the values.
1. calculate sum of numbers till n using recursion.
2. calculate powers of n using recursion.//remember the calculation starts from the point when the base condition is hit. after that only the value starts calculating. else it is just in stack uncalculated.
3. factorial of a number?
4. fibonacci number.
5. check if the given array is sorted or not?  check if arr[0]<arr[1] then sorted, then check for arr[1: last].
bool isSorted(int arr[], int n){
    if(n==1) return true;
    return (arr[0]<arr[1] && isSorted(arr+1, n-1));     //note here arr+1 is a pointer to array and not the array. arr[1:n-1] wont work here.
}

6. print the numbers from 1 to n in increasing and decreasing order?
--> to reverse a thing recursion is the best process.
NOTE: better go with void in recursion data type. or create a temporary variable or static variable to store the values.
```
```cpp
void decr(int n){
    if(n==0) return ;
    cout<<n;        //first print then return n-1
    decr(n-1);
}

void incr(int n){
    if(n==0) return ;
    incr(n-1);      //first do all the returns and finally print the values from last return value(i.e. the base condition) present in the stack.
    cout<<n;
}
```
```cpp
7. to check the first occurrence and last occurence of a number in an array? for this we make two recursive functions one finds the first occurence and other one finds the last occurence. In first we check if the element is equal to the key if yes then we return the index otherwise we return rest of the array.
in second one, we return the array and check later.
int first(int arr[], int n, int i, int key){

    if(i==n){
        return -1;
    }
    if(arr[i]==key) {
        return i;
    }    
    return first(arr, n, i+1, key); //remember in the main function we pass i=0 initially.
}
int last(int arr[], int n, int i, int key){
    if(i==n) return -1;

    int restarr=last(arr, n,i+1,key);
    
    if(restarr!=-1){
        return restarr;
    }
    if(arr[i]==key){    //we check if the current value of the index is = key.
        return i;
    }
    return -1;
}

8. reverse a string using recursion? 
void rev(string a){
    if(a.size()==0) return;
    rev(a.substr(1, a.size()-1)); //or rev(a.substr(1));
    cout<<a.substr(0,1);    //or cout<<a[0];
}
```
```
9. replace pi with 3.14? (boring question)
10.Tower of hanoi? u already know this. BEST PROBLEM OF RECURSION.
11. Move all x in a string to the last of the string. better with iteration.
12. Generate all substring of a string using recursion? see good algos.
13. print all the permutations of a string? lecture 16.4 advanced recursion. see in good algos.
14. count the number of paths possible from start point to end point in gameboard?(boring)
15. count number of possible path in a maze?(boring)
16. find permutations for distinct elements in an array? Same as 13. but here we will do with stl.
--> Time Complexity: O(N!). same as last one. See in good algo. Normal code is also there in good algo.
sort(nums.begin(), nums.end());
do{
    ans.push_back(nums);
}while(next_permutation(nums.begin(), nums.end()));

17. find permutations for elements which can be repeating? Note: if u remove the duplicate from the array then the solution will be wrong as it will generate less permutations. eg: [1,1,2] if we make the array [1,2] then total number of permutaions will be 2 which is wrong. here we get 3 permuations.
Another approach which will work is the store the answer in a set so that all the unique permuations are stored. this will work but it is not much optimised.
See GOOD ALGOS.
SO THE BASIC IDEA IS: while swapping, avoid duplicates.
when we find two same numbers then we continue the loop.
```
Last lecture on RECURSION:(Lecture 16.4)
```
1. TILING PROBLEM: in this question we are given a board(2xn) and a tile(2x1) and we have to find number of way to tile the board using these tiles.(interesting...)--> the solution comes out to be the fibonacci of n. This is the ans. eg: for n=4 ans is 3.
2. Friends pairing problem: Find the number of ways in which n friends can remain single or can be paired up.(useless question...)
```cpp
int friendsPairing(int n){
    if(n==0 or n==1 or n==2) return n;
    return friendsPairing(n-1)+friendsPairing(n-2)*(n-1);
}
so for 4 people 10 is the ans.
```
```
3. 0-1 KNAPSACK PROBLEM: (Very improtant question...)using recursion. SEE good algo.
4. Fractional knapsack is also very easy. We just have to remove to else if part from the algorithm. Means we dont have to put nay other fractional object. We can put any other object if its weight is less than the final remaining weight.
```
#### ------------BACK-TRACKING(using recursion)-------------
```
There are 2 questions in back tracking: 1. Rat in a maze problem, 2. N-queens problem.
Backtracking means if the constraints are not satisfied then from that point only we go 
back to the previous step. Whenever we find that this solution doesn't satisfy then from 
the middle only we will back track.
DEFINITION: Backtracking is an algorithmic-technique for solving recursive problems by 
trying to build every possible solution incrementally and removing those solutions that 
fail to satisfy the constraints of the problem at any point of time.

RAT IN A MAZE: see good algo. we have also implemented dynamic array.
Rat can only move in right direction and in downward direction. So we will be given an 
adjacency matrix of 1 and 0, where 1 means there is a way and 0 means there is no way.
OUTPUT: we have to output a 2D matrix denoting the path of rat by 1 and other paths by 0.

N-queens PROBLEM:   RECURSION AND BACKTRACKING      --> see good algo.
we are given NxN chess board and we have to place n queens so that no two queens attack 
aach other.
we have to place one by one and check for safe places in other rows correspondingly.

to check we have to check if there is already a queen in that column or diagonal.
we only need to check in the upper hemisphere, and not in the lower hemisphere because
we have't placed our queen there so it is not possible that any queen checks from lower 
hemisphere. We don't need to check for that particular row also because we are in a row
where no queen is placed yet. so we only need to check for the columns and diagonals
(both left and right of upper hemisphere.)
```
### -------learning vectors--------
```cpp
vector<int> v;  //where int is the data type and v is the name of the vector.
to insert elements: v.push_back(11);
to delete the last element: v.pop_back();
to get the length of the vector: v.size();
for(int i=0; i<v.size(); i++){
    cout<<v[i]<<endl;
}
//---> another way to traverse the vector is through iterator.
vector<int>::iterator it;
for(it=v.begin();it!=v.end();it++){
    cout<<*it<<endl;
}
//---> another simple way is by auto. we are telling our compiler that u decide what type of data is stored according to the initailization of vector
for(auto element: v){
    cout<<element<<endl;
}
ANOTHER WAY:
vector<int> v2 (3,50);
//there are three elements and all are initiated with 50. 
// 50 50 50

//for swapping two vectors: swap(v,v2);
//for sorting: sort(v.begin(),v.end());
-------------------------------learning pairs------------------------------------------
1. similar to dictionary in python.
pair<int,int> p; //here both data types can be different also according to our choice.
//to access
pair.first=1; //for accessing pair<first,second> p where first and second are datatypes.
pair.second=2;
----------------------------------------------------------------------------------------------------------------
```

Merge Sort: Divide and conquer. In this we find the mid of the array and divide our array into two parts. similarly we divide our arrays into multiple parts. REMEMBER: An array with single element is always sorted array. Now we have to call a merge functions which merges two sorted arrays. It applies two pointer approach. i on first array and j on second array. and we have to checck which one is smaller. Here we also use a temporary array for storing values.

Quick Sort: Divide and conquer. In this we select an element(pivot) and put it in its right place which means all the elements left side are smaller and all the elements right side are greater than that element. To find the pivot element we use two pointer approach. And we find the pivot element through a function called partition. Pivot can be any element of our choice either it can be the first element of the array or the last element of the array. and now with the two pointer approach we find the correct positionof the element. Here i and j are important. Significance of i is that it will be denoting the last element smaller than pivot.
now we iterate: if j < pivot then i++ and swap i and j and then j++. if j>pivot then only j++. And finally we swap pivot and i+1.
now the left and right subarray are not sorted so we have to apply again.

Count inversion problem: implementation of merge sort. lecture 19.3 (boring)

Count Sort: Find the count of every distinct element. Calculate the position of each element in sorted array. Easy h...u already know.Code with harry is best for count sort.

DNF sort(0,1,2)sort[Time complexity: O(n)]: A given array contains only 3 elements 0,1,2. so we have to sort them. So we have to do 3 pointer approach. low, mid and high. RED, WHITE, BLUE. red for 0 , white for 1 and blue for 2.
here we start from mid pointer. 
Note: low and mid pointer points to the starting of the array. high pointer points to the last element of the array. 
if mid==high then our array becomes sorted.
we check if arr[mid] is:
if 0, swap arr[low] and arr[mid], low++, mid++;
if 1, mid++;
if 2, swap arr[mid] and arr[high], high--;

WAVE SORT: this is not sorting actually. we have to form a wave. (very simple)--> TIME complexity: O(N/2) or O(n).
a[0]>=a[1]<=a[2]>=arr[3]<=arr[4]...
we check for the odd indexes first. we check if it is smaller than its neighbourhood or not. if not then swap. note: we are checking for odd indexes so we have to take a jump of 2.
ONLY THE CATCH: here is that we have to check for the odd indexes and check whether it is smaller than both the neighbours or not If not then swap the elements. and we have to move on to next odd element.

------------------------------------------------------OOPS IN CPP---------------------------------------------------------------
SAME AS JAVA OOPS...
~ is used to make a destructor. NOTE: always when the program terminates at return 0; all the deafult destructors are called.

operator overloading:
we can add two built in data type members, but we can't add two user defined data memebers of a class. for that we have to redefine the operator inside funtion and it creates additiotnal feature of that operator. like we can use + in strings to concatenate, but string is built in data type, so it works. And of course the real meaning of the operator doesnot change.
BEST EXAMPLE OF OPERATOR OVERLOADING IS : COMPLEX NUMBERS ADDITION.

https://www.geeksforgeeks.org/operator-overloading-c/

INHERITANCE IN CPP: Single, Multi-level, Multiple(not in java), Hybrid, Hierarchical.
1. Single inheritance: 
class A{
    public:
    void func(){
        cout<<"Inherited"<<endl;
    }
};
class B : public A{     //single inheritance
};

int main(){
    B b;
    b.func();
    return 0;
}

2. Multiple inheritance:

class A{
    public:
    void func(){
        cout<<"Inherited"<<endl;
    }
};
class B {     
    public:
    void bfunc(){
        cout<<"func b"<<endl;
    }
};
class C : public A, public B{       //multiple inheritance

};

int main(){
    C c;
    c.bfunc();
    c.func();
    return 0;
}

3. Multi-level inheritance:
class A{
    public:
    void func(){
        cout<<"Inherited"<<endl;
    }
};
class B : public A{     
    public:
    void bfunc(){
        cout<<"func b"<<endl;
    }
};
class C : public B{       //multi-level inheritance

};

int main(){
    C c;
    c.bfunc();
    c.func();
    return 0;
}
4. Hybrid inheritance: Mixture of multiple and multilevel inehritance. (Not in Java)
5. Hierarchical inheritance: Big image of multiple inheritance.(not in java).

POLYMORPHISM IN CPP:
u know polymorphism from java.
polymorphism is of two types: 1. compile time polymorphism 2. run-time polymorphism
1. compile time polymorphism: it is achieved through 1. function overloading(very easy) 2. operator overloading(see above)
2. run-time polymorphism: it is achieved through virtual functions. imagine if there is a function with same name in both base and derived class. so the compiler becomes confused. so Basically we put virtual keyword to the base class so that it is not called during runtime.

------------------------------------------------LINKED-LIST-----------------------------------------------------------------
NOTE: IF YOU WANT TO INSERT ELEMENTS OR CREATE A LINKED LIST LIKE ARRAY THEM take create an array and using for loop iterate over it and using insert at end in the for loop insert all the elements of array in linked list.

insertion, deletion in linked list.
go to linked list folder for linked list quesitons.

1. REVERSE A LINKED LIST:

(i) iterative way of reversing a linked list:
we use 3 pointer approach. previous, current and next pointers.  initially previous is at null, current is at head and next is at head->next.
so we change the link of current-> next to previous<-current. now we move all the pointers with one step.
same now we again do current->next to previous <- current.
break the loop if current pointer is at null. now change the head pointer to the previous pointer.
(ii) recursive way of reversing a linked list:
we call reversive function for head node. and it returns us a linked list like this.
1->2<-3<-4 if the linked list earlier was 1->2->3->4. now we just reverse the head node pointer.

2. REVERSING K NODES IN LINKED LIST:

if k=2 then we have to reverse the first two nodes then the other two nodes and the other two nodes and so on.
1->2->3->4->5->6 is the linked list then for k=2;
2->1->4->3->6->5
Approach: here we make a iterative function to reverse the first k nodes. and for the remaining linked list of k+1th nodes we call the recursive function. 
now we have to join these two linked list. means we have to join our first k nodes linked list with the linked list we got from recusion in the right format.
so the head remains at 1 and the previous pointer points at 2 in the first k nodes. now we have to point that head to the linked list we got from recursion. so we do, head->next=linkedlist we got back from recursion.
therefore we return 2 which is the prev pointer and our new head.

3. DETECTION AND REMOVAL OF CYCLE IN LINKED LIST (a.k.a Floyd's Algorithm or Hare and Tortoise Algorithm):
--> for detection of cycle:
if next of two nodes points to same node then it forms a cycle in linked list.
let hare and Tortoise be at head node in the beginning and let hare moves with 2 nodes forward at a time and tortoise move with one node at a time.
if hare and tortoise comes to same node then we can say that there is a cycle in linked list. NOTE: hare and tortoise can come to any node in the circle, any node but will always be a same node for each time. we can only find that node by solving and not by guessing.

in real we use fast and slow pointer.  and the base condition is that if fast=null or fast->next=null then stop.

--> for removal of cycle:
it is now back to hare and tortoise story. after we find that hare and tortoise are at same node. then we bring the hare to head and now move them with one step only each. When we find out that both hare->next and tortoise->next points to same element then this indicates the starting of the cycle.
now tortoise->next=NULL; this is the removal of cycle in linked list.

IMPORTANT OBSERVATION: m = l - n; where m is the length from head to starting point of circle. l is the length of circle and n is the point where both hare and tortoise meet at first.
Therefore, we now run both fast and slow pointer with same speed.

4. (KAPPEND) APPEND LAST K NODES TO START OF THAT LINKED LIST:  
1->2->3->4->5->6        for k = 3
ans = 4->5->6->1->2->3

here we are given length of linked list, value of k and the linked list.

APPROACH: we now start traversing the linkedlist with head at the first element and at (l-n) node we put the pointer newTail and the new head of the linkedlist will be newTail->next and we point that with new head pointer and at the last element we place our tail pointer. 

now, we just change the links.
newHead=newTail->next;
newTail->next = NULL;
tail->next=head;
and return newHead.

5. FIND INTERSECTION POINT OF 2 LINKED LIST: we are given two linked list and they intersect at some point imagine like a tuning fork. that the two ends are the linked list and the handle is the intersection point of the linked list.
if both linked list are different then we return that there is no intersection point.

APPROACH: we find the length of both the linked list and we subtract them. we use two pointer approach here. here we place ptr1 on first linked list and ptr2 on second linkedlist where ptr2 is the head of the second linked list and ptr1 is at position (l1-l2) of the first linked list means both are now equal step back at before the intersection point you can imagine like this. now we move both the pointers before any one of them gets null and we check if at any node ptr1==ptr2. we return the value of that pointer.
Time complexity: O(length of the longer linked list);

6. MERGE TWO SORTED LINKED LISTS: we are given two sorted linkedlist. 
(i) iterative.
(ii) recursive.
note: you can't run both iterative and recusive in one program so i have made two programs.
TIME Complexity: O(sum of length of both linked list)

It is same as merging two sorted arrays.
we use 3 pointer approach here. we make a dummy node. now ptr1 points to linkedlist1, ptr points to linked list 2 and ptr3 points to dummy node.
Now we compare ptr1 and ptr2 whichever is small we add that to ptr3 and move that pointer and again compare till anyone of the node points to NULL. if any node points to null then we add the complete another pointer to the last of ptr3.
Note: our dummy node is empty node so we return pt3->next because we have to return a linkedlist which first element is an element and not an empty element.

7. PUT EVEN ELEMENTS AFTER ODD ELEMENTS IN LINKED LIST:     TIME Complexity: O(n)
1->2->3->4->5->6 becomes 1->3->5->2->4->6.
we use three pointer approach. one odd ptr, one even ptr, and one evenStart ptr to store the starting index of even pointer.
Now the approach is simple. 
we put odd->next=even->next; odd=odd->next;
we put even->next=odd->next; even=even->next;
if even->next==null; then we understand that we have reached the end of the list. so now, odd->next=evenStart;
if odd->next==null; then it is sure that even->next is not null. so we have to make it null and odd->next=evenStart;

----------------------------------------------------------------------------------------------------

DOUBLY LINKED LIST: easy hai only insertion and deletion.

CIRCULAR LINKED LIST: complete implementation by apni kaksha.

Time complexity using master's theorem: easy only three cases.

------------------------------------STACK-----------------------------------------------------------
LIFO: last in first out.
now we can use stl for stack 
stack <int> s;
1. Reverse a string using stack: We can and should use stack to reverse anything. It is better than recursion and easy also.
2. Reverse a stack: Without using another stack. We use recursion here.
How to insert at bottom in a stack? we pop out all the elements and then we push the element which we want at bottom. and the callback funtion pushes all the elements back to the stack now.

INFIX, PREFIX(Polish notation) AND POSTFIX(reverse polish notation): you know already.
1. PREFIX EXPRESSION EVALUATION: we are given a prefix expression we have to return the final value say +75 gives 12.
we use stack. we push the elements from back of the string if it is an operand. if we get a operator then we pop out two elements perform the operation and push it back to stack. until the stack is empty. O(N) time complexity.

2. POSTFIX EXPRESSION EVALUATION: we are given a postflix expression we have to return the final value say 75- gives 2.
we use stack. Only difference is that here we start from beginning.

3. INFIX TO POSTFIX EVALUATION: we are given an infix string we have to convert it into postfix string.

4. INFIX TO PREFIX EVALUATION: we are given an infix string we have to convert it into prefix string. NOTE: 

5. BALANCED PARENTHESIS: easy hai ye kaafi.

----------------------------------------------QUEUE----------------------------------------------------------
FIFO: first in first out.
In stack we only have a top pointer but here we have 2 pointers. front and back.
Some operations: enqueue(x): inserts element at back using back pointer, 
dequeue(): removes element from front pointer, 
peek(): returns the element stored in front pointer. simmilar to stack.top(), 
empty(): if front==rear then queue is empty.

NOTE: queue is waste of storage because only the pointer moves here and nothing happens to elements already inserted.

1. Linked List implementation of Queue:
Note: queue using linked listt is good because there is no shortage and excess of size in linked list implementation of queue.
(i) for push: we insert at back.
(ii) for pop: we delete the first node.
(iii) for peek: we return the head node or the front node.
(iv) for empty: we check if front pointer is null or not, because when front pointer moves after the rear pointer, we know that rear pointer points to NULL. So the front will point to null in this case(when front>rear) and initally we know front==NULL.

2. Queue implementation using stack:    very very easy.
APPROACH 1: we use two stacks. for enqueue we use stack1 and for dequeue we pop out the elements and push into stack2 and then we pop out from stack2. Time complexity of enqueue is O(1) and dequeue is O(n).
APPROACH 2: instead of two stack we can use one stack and one function inbuilt stack. enqueue operation is same. For dequeue:
if stack1 is empty then print error.
if stack1 has only one element then return it
if stack1 has more than one element, recursively pop eveything from stack1, store the popped item in res, push res back to stack and return res.

3. Implementing stack using Queues: Here we use two queue. One approach is by making the push operation costlier and the another approach is by making pop operation costlier. THIS IS NOT IMPORTANT QUESTION SO WE CAN LEAVE IT.

------------------------------------------------DEQUE--------------------------------------------------------------
DEQUE: stands for doubly ended queue. here we can push and pop both from both ends.
1. We can push and pop from the end.
2. we can insert and delete from start.
--> simply we can use it from STL.

Q. SLIDING WINDOW MAXIMUM?
APPROACH: HERE, the approach is that we first find the first sliding window value. i.e. by running for loop from i=0 to i=k, where k is given in question. now we us another loop where we decrease the value from beginning and add the next upcoming values. 

--> Here we are given an array and a number k. we have to find the max of all the elements containing in every subset which has length 3.
So we have to print maximum of all the elements in the window.
[1,3,-1,-3,5,3,6,7]
--> 3,3,5,5,6,7
approach 1: using for loop. TIME COMPLEXITY: O(N*k) and Space complexity: O(1)
approach 2: Using deque: O(n) and space complexity O(k)
in deque we only store the useful elements inside deque: useful elements are those elements which doesn't have any smaller number on its left. or you can think that if k = 3 then the useful elements are the elements from the subset of length 3 which are in decreasing order from left to right and we remove the last element.
say [4,1,3,5,1,2,3,2,1,1,5].
the ans of sliding window maximum is 4,5,5,5,3,3,3,2,5
so the useful elements are as follows.
[4,3] because we first insert [4,1] and then we insert 3 and we find out that one is there which is smaller than 3 so we remove 1 and we get [4,3].
[5] because in next step we remove 4 because it is not a part now and we are left with [3] so we insert 5 and we find that 3 is smaller so we remove 3 and add 5.
[5,1] since 1 is smaller so we just insert it.
[5,2] since 1 is smaller than 2 so we remove one and insert 2.
[3] we remove 5 because it is not a part anymore. we remove 2 because 3 is greater than 2.
[3,2]
[3,2,1]
[2,1,1]
[5]
here our ans is always the first element of the array. so we make deque to make the above subset array and with pop_front() we get our maximum value.
NOTE: we have to maintain a decreasing order and we have to store the index of elements in deque and not the elements. above one is only for understanding.

-------------------------------------------------------------------------------------------------------------------------
-------------------------------------------STACK QUESTIONS--------------------------------------------------------------------
1. LARGEST RECTANGLE IN A HISTOGRAM: use of stack.
Given an array. Each element represents the height of the HISTOGRAM bar and the width of each bar is 1. Find the area of largest rectangle in HISTOGRAM.
STACK APPROACH: we will push the elements if they are in increasing order. and if we get a smaller element then we get a potential area so we will find out the area. and we will find out the maximum of all such areas.
For visualisation you can see video. it is bookmarked.

2. TRAPPING RAINWATER HARVESTING: use of stack. 
Given non-negative integers representing an elevation map where the width of each bar is 1. Compute how much water can trap after rain.
ARRAY: [0,1,0,2,1,0,1,3,2,1,2,1] here ith element represents the height of the ith bar.
understand it like you are given a model we have to find out the maximum water this model can collect.
here the ans is 6.
STACK APPROACH: if we are getting decreasing elements then water will move away. so as soom as a big element is found. a countainer is made and it can store the water.

3. REDUNDANT PARENTHESIS: means it there is any extra unncessary parenthesis in the given expression or not. USE of stack.  HERE WE ONLY USE SMALL BRACKETS FOR SIMPLICITY.
Given a valid mathematical expression, find whether it have redundant parenthesis or not. It contains the following operators. '+', '-', '*', '/'. 
((a+b))--> yes, it has redundant parenthesis.
(a+(a+b))--> no, all is fine.
APPROACH: We have to use stack and push the parenthesis and the operators inside the stack. if we find a closing parenthesis then we have to make sure that there is alteast one operator present before we find its other pair. if no operator then it is redundant parentheis i.e. unncessary parenthesis.

4. THE STOCK SPAN PROBLEM: 
The span of the stock price today is defined as the maximum number of consecutive days(starting from today and going backwards) for which the price of the stocks was less than or equal to today's price.
Find the span of the stock for all the days.
ARRAY: [100, 80, 60, 70, 60, 75, 85]
ANS:   [1, 1, 1, 2, 1, 4, 6]

STACK APPROACH: here we make a stack of pairs. in which the first element stores price and second element shows days.
now we push (100,1) then (80,1) then (60,1) then we get get 70 which is greater than 60 so we pop out 60 and we push (70, 1+(st.top.second)); now we push (60,1) now we check if 75 is greater or not. so we pop 60 ans push(75, 1+(st.top.second)) we again pop 70 and we finally push(75, 1+1+2) i.e. (75,4) and at last we push(85, 1+4+1) i.e. (85,6)

5. 3 SUM problem: You already know two sum(leetcode) If we use brute force approach then we have to find all the combinations who sum is equal to given sum but it will be of T.C. O(n^3).
So we first sort the array and use two pointer approach.
Given an array and a value, find if there exists three numbers whose sum is equal to the given value.
n=6, target=24, arr= 12, 3, 7, 1, 6, 9
OUTPUT: true(12,3,9)
TWO POINTER APPROACH:
so we fix one pointer and send for two sum problem to find if there exist any sum who's value is target - current pointer value.
if there exist any element then there exist a value because we will simply add the elements we get from two sum to the current pointer element and voila! we get the value.
We know the time complexity of two sum problem is O(n) so here we are traversing the array also so our new T.C. becomes O(n*n) so O(n^2) and for sorting it takes O(nlog n) so final time compelxity is O(n^2).
TwoSum: it is simple. O(nlog n) algorithm. we sort the elements(O(nlogn)) it uses two pointers low and high. low is at 0 index and high at last index. we find if curretn sum i.e arr[low]+arr[high]==target then return true. else if current sum<target then i++; if currentsum > target then high--; and we run the while loop (low<high).

6. MAXIMUM CONSECUTIVE ONES: 
we are given an array A consisting of 0 and 1. we have to find lenght of longest contigous subarray that contains only 1. But here we are given k. which means that we can change atmost k 0s to 1. and then find out the longest subarray.
APPROACH: we have to find longest subarray with k zeros.

-----------------------------------------------BINARY-TREE---------------------------------------------------------------
WITHOUT RECURSION YOU CAN'T LEARN AND MAKE TREE. THERE IS ONLY AND ONLY RECURSION IN TREE.
--------------------------------------------------------------------------------------------------------------------------
basic concepts you already know.
To make a tree:
struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int value){
        //this is the constructor
        data=value;
        left=NULL;
        right=NULL;
    }
};
Binary tree traversals: Preorder, Inorder, Postorder.
void preOrder(struct node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data;
    preOrder(root->left);
    preOrder(root->right);
}
1. Build tree from PreOrder and Inorder. here we build left subtree and then right subtree.
2. Build tree from PostOrder and Inorder. Similar but opposite. here we first build right subtree and after that we build left subtree.

NOTE: We can't build tree from just preorder and postorder traversal. It can only be possible if it is a complete binary tree else the tree structure may vary.

3. LEVEL ORDER TRAVERSAL: We implement this using queue. It is similar to BFS where the firdt element is the root itself.
Imagine a tree with Level order traversal: 1,2,3,4,5,6,7. O(n)

so we use queue data structure here. We first insert root and then we insert a null representing the end of first level. So in our queue we have 1, NULL. elements inserted.
Now we dequeue from queue and we get 1. so we now traverse for left and right childs of 1. so we push 2 and 3 to our queue so our queue becomes NULL, 2,3. so if we pop out hten we get NULL which represents the end of 1st level. So we pop out the null and push it back to the queue. Then pop out 2 and insert the elements in queue.
so the elements in queue are 3, NULL, 4,5.
Again we pop out 3 and push it back. so our queue becomes NULL, 4, 5, 6, 7. next we pop out NULL and it represents the end of 1st level. so we again push that NULL to the queue.
We then pop 4 and print it and check if it has childrens or not. similarly for othed. 
3. At each step, chek if sum divisible by 3 or not. If it is, then print the elements.TimeComplexity: O(n) and we finally print them all. we notice that after we pop out NULL after queue is empty so we have completed our traversal.

4. Find the sum of nodes at kth level. O(n)
5. Count all the nodes in a binary tree. We have to count the number of nodes in a binary tree and return it. O(n)
APPROACH: here we recursively count for the left sub tree and right sub tree and add +1 to it for including the root node. We do it recursively.
int countNodes(Node* root){
    if(root==NULL){
        return 0;
    }
    return countNodes(root->left)+countNodes(root->right)+1;
}

6. Sum of all nodes in a bianry Tree: Left Subtree sum + Right Subtree Sum + node Value.
Or you can easily do inorder traversal and add the values.O(n)

7. Height and diameter of a Binary tree: We recursively call for the height of the left subtree and right subtree and find there maximum and add one to it. 

TimeComplexity: Height: O(n), Diameter: O(n^2) it can be done in O(n) if we merge the height function in diameter only. See the apni kaksha video.
int findHeight(Node* root){
    if(root==NULL){
        return 0;
    }
    return max(findHeight(root->left),findHeight(root->right))+1;
}
Diameter of a tree: Number of nodes in the longest path between any two leaves. Diameter of the tree can pass through the root node or can't also pass through the root node.
APPROACH: We find left diameter and left height and right diameter and right height. If our diameter is passing through the root then the diameter is leftheight+right height+1, else it is the max of leftDiameter or RightDiameter.
max(leftheight+rightHeight+1, leftDiameter, RightDiameter)

8. Sum Replacement in Binary tree: Replace the value of each node with the sum of all subtree nodes and itself. It is basic common sense question. Time Complexity: O(n)

9. Balanced Height Binary Tree: For each node, the difference between the heights of the left subtree and right subtree <=1
abs(left height- right height)<=1. O(n^2) we can reduce it to O(n) with the same approach as diameter. we pass the height pointer in both.

10. Right view of BT: here we go and see our binary tree from right side and whatever nodes we see we print them. 
APPROACH: we do the level order traversal here and we print the right most node in level order traversal. Note: we used queue for level order traversal. 
Time Complexity: O(n)

11. Left view of BT: Very similar to right view of BT. Here just we have to print the first element of the order.
Time Complexity: O(n)

12. Find distance between 2 nodes of a binary tree: Find the distance between two nodes in a binary tree. The distance between two nodes is minimum number of edges to be traversed to reach one node from another.
APPROACH: Find the LCA(Lowest common ancestor). Find distance of n1 (d1) and n2 (d2) from LCA. return d1+d2.

13. Flatten a binary Tree: Given a binary tree, flatten it into linked list inplace(means we have to solve int that tree only. we dont have to do traversal and create a linked list from it). After flattening, left or each node should point to NULL and right should contain next node in preorder sequence.(It is NOT allowed to use any other data structure)
SIMPLE UNDERSTANDING: We have to leave the left subtree as it is. we have to append the right subtree to the left subtree to its last node. then recursively we have to do this only.
APPROACH: 1. Recursively, flatten the left and right subtrees.
        2. Store the left tail and right tail. Tail means the last element.
        3. Store the right Subtree in temp and make left subtree as right subtree.
        4. Join right subtree with left tail.
        5. return the right tail.

14. Print all nodes at Distance K: we have to print all the nodes at distance k from the given node. We can find and print the nodes in our subtrees and also we can find nodes in our ancestors tree. We have to print all of them. We will be given a root node, a node from where we have to calculate the distance and k is the distance.
Case 1: Nodes Subtree. we travel down and we decrease our k by 1. if k==0 then we have to print those nodes.
Case 2: Node's ancestors. We have to find the distance of all ancestors from target node and store it in variable d. For all ancestors search for other subtree nodes like in CASE 1. for (k-d) distance.
If the given node is in left subtree then we search in ancestors right subtree and if our node is in right subtree then we search in left subtree. In this way we reduce our case 2 in case 1.

15. LOWEST COMMON ANCESTOR for TWO nodes: we have already done it. It is simple.

16. MAXIMUM PATH SUM IN A BINARY TREE: maximum possible sum of a path in a binary tree, starting and ending at any node.
We use recursion.
APPROACH:   1. Node Val.
            2. Max path through left child + node val
            3. Max path through right child + node val.
            4. Max path through left child + Max path through right child + node val.

---------------------------------BINARY SEARCH TREE--------------------------------------
1. Creating a BST and doing inorder traversal.

2. Searching in a BST: easy hai.
2. delete in a BST:
Case 1: If it is a leaf node then we directly free that node.
Case 2: A node which has only one child: Replace the node with child and delete the node.
Case 3: If it has 2 childrens. 
        Step 1: In this case we have to find our inorder successor.
        Step 2: Replace(or swap) the node with inorder successor.
        Step 3: We now use the case 1 now to delete the leaf node.

3. BUILD BST from preorder: simple we know inorder is the sorted sequence then we can sort the given preorder and find our inorder and in this way now we have both inorder and preorder So we can make our tree easily.
BUT here we will follow a different approach. We will define min and maximum value of node at each step. it is easy. (min, max). 
TIME COMPLEXITY: O(n);

4. Check for BST? We have to check if the given tree is BST or Not. we simply do the inorder traversal of the tree and check if the traversal is sorted or not.
We have to check the properties of bst.
1. All nodes of the left subtree are lesser than the node itself.
2. All nodes of the right subtree are greater than the node itself.
3. Left and Right subtrees are also binary trees.
4. There are no duplicate nodes.
5. The InOrder traversal of a binary search tree gives an ascending
sorted array.

5. SORTED ARRAY TO A (balanced)BINARY SEARCH TREE? ye to easy hai.
APPROACH:   1. make middle of the tree as root.
            2. recusively do same for the subtrees.
                start to mid-1 for left subtree.
                mid+1 to end for right subtree.

6. CATALAN NUMBERS: Catalan numbers are sequence of natural numbers that occur in various counting problems often involving recursively defined objects.
their closed form is in terms of binomial coefficents.
Cn=(1/(n+1))2nCn
C0=1; 
C1=1; 
C2=C0C1 + C1C0=2; 
C3=C0C2 + C1C1 + C2C0=5
C4= C0C3 + C1C2 + C2C1 + C3C0 = 14

So how can we find the nth catalan number?
It is easy. we can use recursion to find out nth catalan number but it has very high time compelxity so we have to use dynamic programming for this.
Let's see the APPLICATION OF catalan numbers.
1. Possible BST's.  --> if n is the number of nodes then catalan(n) is the number of possible BST possible for n nodes.
2. parenthesis/bracket combinations
3. Possible forests
4. Ways of triangulations
5. Possible paths in matrix
6. Dividing a circle using N chord.
7. Dyck words of given length & much more.

7. POSSIBLE BST FOR N NODE:--> if n is the number of nodes then catalan(n) is the number of possible BST possible for n nodes.

8. Zig-Zag Traversal: it is kind of level order but one time it is right to left so the next time it is left to right.
Approach:   1. use 2 stacks - current level and next level.
            2. variable leftToRight
            3. if LeftToRight, push left child then right else, push right child then left.

9. Are BST indentical? 
APPROACH:   1. If both empty, return true;
            2. If both non-empty,
                a. Check that the data at nodes is equal
                b. Check if left subtrees are same.
                c. check if right subtrees are same.
            3. if (a,b,c) are true, return true else return false.

10. Largest BST in a binary Tree: We have to return the size of the largest bst in a given binary tree.
APPROACH:   for each node store the following information:
            1. min in subtree
            2. max in subtree
            3. subtree size
            4. size of largest BST
            5. isBST
            Recusively, traverse in a bottom-up manner and find out the size of largest BST.
Or you can do inorder traversal of the tree and we have to find the largest sorted array.

11. Restore BST(Good question): The problem is that 2 nodes in a BST are swapped. Our task is to restore(correct) the BST.
APPROACH: Inorder traversal of BST is a sorted array.
2 elements in sorted array are swapped.
CASE 1:     1. swapped elements are not adjacent to each other.
CASE 2:     1. Swapped elements are adjacent to each other.
APPROACH: we ise three pointers approach: first, last and mid.
for CASE 1: {1,8,3,4,5,6,7,2}
            First: previous node where 1st number <previous[8];
            Mid: number where 1st number <previous[3]
            last: 2nd Node where number < previous[2]
for CASE 2: {1,2,4,3,5,6,7,8,9}
            First: previous node where 1st number <previous[4]
            Mid: number where 1st number < previous[3]
            Last: NULL

----------------------------------------SET---------------------------------------------
1. Ordered set              2. Unordered set
NOTE: you can refer you book for set.
1. Ordered Set: - implemented using balanced BST.
                - O(log N) for everything.
                - for insertion we use s.insert(); 
2. Unordered Set: - implemented using Hashing.
                  - elements are not in sorted order.
                  - O(1) for searching but O(n) for deletion.
----------------------------------------------------------------------------------------

---------------------------------Binary Search CHALLENGES------------------------------------------
1. PLACE ELEMENTS TO MAXIMUM MINIMUM DISTANCE: This is a Binary search problem.
-->this is very interesting question and easy concepts. Just she explains it hard.
Given is an array with n elements that represents n positions along a straight line. Find K elements such that the minimum distance between any 2 elements is the maximum possible.
APPROACH:   1. sort the array for binary search technique.
            2. pick middle element as result and check for its feasibility.
            3. If feasible, search the right half of the array with larger minimum distance.
            4. else search the left half of the array.

2. Allocate minimum Pages: NOTE: this is binary search problem. Not bst.
n - number of pages in n different books( ascending order)
m - number of students
All the books have to be divided among m students, consecutively. Allocate the pages in such a way that maximum pages allocated to a student is minimum.
APPROACH:   1. Apply binary search for min and max possible values for 'max' pages.
note: here the min no. of pages is the first element and the max value if the total sum of the array.
            2. check feasibility of this choosen value.
Assign pages to each student in sequencial manner, while the current number of allocated pages don't exceed the value set by binary search. 
If during allocation the number of students don't exceed the limit of 'm' then the solution is feasible. Else, it is not.

3. Painter's Partition Problem: This is similar to minimum Pages problem. Only some changes. Here we dont use ans instead we use low which only stores and give us the answer.
n - length of n different boards
m - painters available
A painter paints 1 unit of board in 1 unit of time and each painter will paint consecutive boards. Find the minimum time required by the painters to paint all the boards.

4. Search in Sorted and Rotated Array: Beautiful question. NOTE: this is horizontal rotation only.
You can frame a good question if you rotate vertically.
We are given an ascending sorted array that has been rotated from a pivot point(unknown to us) and an element X. Search for X with a complexity less than linear search.
Original array: [10, 20, 30, 40, 50].
Rotated array: [30, 40, 50, 10, 20]. note: the left and right subarray are sorted if pivot is your mid.
APPROACH:   Find the pivot point. Then apply binary search in left half and right half.
            To find the pivot point: It is a single point where it is greater than the element right to it. arr[i]>arr[i+1];
//we can use binary search recursive.

5. Find the peak element: 
For a given array, find the peak element in the array. Peak element is one which is greater than both, left and right neighbours of it self.
    Corner Case: if the array is in ascending order then the last element is the peak element.
                 if the array is in descending order then the first element is the peak element.
                 if all the elements in array are same then all the elements are peak element.
NOTE: there can be more than one peak element in an array.
APPROACH: use binary search, analyse indices from 0 to n-1. 
Compute mid and for each mid check if arr[mid] is a peak element.
Else if arr[mid-1]>arr[mid], check left for peak.
Else if arr[mid]<arr[mid+1], check right for peak.
Given: arr[]={1,3,20,4,1,0}. Start=0, end=5. mid=2 and coincidently mid is also the peak element.

6. Maximum Sum Subarray sliding window challenge: Max sum subarray of size=K and sum<x;
For a given array and integers K and X, find the maximum sum subarray of size K and having sum less than X.
NOTE: we just have to return the sum. It is very simple sliding window.
APPROACH 1: Compute sum of all possible subarray of size K. T.C.= O(n*k)
APPROACH 2: Sliding window approach.
    1. Calculate sum of first k elements.
    2. Initialise ans with this sum.
    3. Iterate over the rest of the arr.
        keep adding one element in sum and removing one from start.
        Compare new sum with ans in each iteration.
TIME COMPLEXITY: O(n);

7. Minimum Size Subarray sliding window challenge: Smallest subarray with sum>X.
For a given array and an integer X, find the minimum subarray size for which sum > X.
APPROACH 1: Compute sum of all subarray and check the condition.
TIME COMPLEXITY: O(n^2).
APPROACH 2: Sliding window approach.
    1. use variables ans, sum and start.
    2. iterate over array and start adding elements to sum.
    3. if sum>X, remove elements from start.
Time Complexity: o(n)
NOTE: we are looking for subarray > x and not even equal to x.

8. Number formed from subarray of size K, divisible by 3: 
For a given array and an integer K, check if any subarray of size K, exists in the array such that elements in subarray form a number divisible by 3.
Given: [8,23, 45, 12, 56, 4]. and k = 3. so the number formed from last 3 elements is 12564. and it is divisible by 3. 
APPROACH: we know if the sum if divisible by 3 then the number formed is also divisible by 3. 
    So, we use our sliding window approach.
    1. sum of initial K elements from the array.
    2. Use sliding window technique and one by one, start subtracting elements from the beginning and adding from the end. 
    3. At each step, chek if sum divisible by 3 or not. If it is, then print the elements.
TimeComplexity: O(n).

9. Subarray with size K with palindromic concatenation: 
For a given array and an integer K, check if any subarray of size K exists in the array such that concatenation of elements form a palindrome.
APPROACH 1: Generate all the subarrays of size K. TimeComplexity: O(n^2).
            Check if their concatenation forms a palindrome. TimeComplexity: O(n).
    Total TimeComplexity: O(n^3)
APPROACH 2: Sliding window approach.
    1. Store concatenation of initial K elements.
    2. Iterate over the array and start deleting elements from the start and adding elements from end.
    3. At each step, check if the concatenation is a palindrome or not.
    TimeComplexity: O(n^2)

10. Maximum perfect numbers in length K:
For a given array and an integer K, find the maximum perfect numbers in a subarray of size K.
Perfect numbers are numbers whose sum of the divisors including the number itself is twice the number or if we exclude the number then the sum of proper divisors if the number.
    6-> 1,2,3 --> 1+2+3=6
APPROACH: Convert the given array into binary array of 0 and 1. only. 1 represent the binary numbers.
        Use Sliding Window approach.
    Time complexity to find perfect number: O(sqrt(n))
    Time complexity for sliding window: O(n)
    Final Time complexity: O(n*sqrt(n))   

-------------------------------------------HEAP-----------------------------------------------------
Heaps are binary tree and not necessarily BST.
MIN HEAP AND MAX HEAP.
1. HEAP-SORT: NOTE: If we have to pass vectors in functions then passing the reference to vector is good practice and consumes less time complexity.
2. HEAP-STL: In STL we have max heap implemented. It is known as priority queue.
MAX HEAP: priority-queue<int, vector<int>>
MIN HEAP: priority-queue<int, vector<int>, greater<int>>
Operations:     1. push: O(log n)
                2. pop: O(log n)
                3. top: O(1)
                4. size: O(1)
3. Median of running stream: Numbers are coming and we have to tell median after each input.
APPROACH: median is the middle element so if the total number of digits are odd then we can simply return the middle element but if the total number of elements are even then we have to use 2 heaps. One min heap and other one max heap. and we will pop out elements from both of them and we will divide them by two. in this way we get the median.
We will put one element in maxheap first. then when the second element come then we put the other number in min heap and we get the top element and we find the average. if the number of elements in any heap is less than the other then we get the top element of that heap and that is our answer.

4. MERGE K SORTED ARRAYS: we know how to merge 2 sorted array. So we can use that but the time complexity will be large so we use heap for merging k sorted arrays.
APPROACH: Efficent solution using HEAPS.
1. Create a mini heap of pairs.
    Pair->{value, array number}
2. Insert{first element, array number} of all the sorted array into MinHeap.
3. Main Idea: We will pop element from MinHeap and store into the answer Array. Insert the next element of the sorted array into the MinHeap.
4. We also need to keep track of the indices of the elements.
--> this is a good question here we apply the sorting of pairs also in which the first of pair gets sorted. 

5. Smallest Subsequence with sum K:
In Subsequence the order remains the same but it is not necessary to be contigous block of elements.
"Every subarray is a subsequence but every subsequence is not a subarray"
APPROACH:
1. Keep a maxheap and insert all the elements.
2. Keep popping the elements and keep adding them to a variable sum and maintain cnt.
3. When sum>=k, then quote the answer (cnt).

-----------------------------------------HASHING--------------------------------------------------
You already know hashing.
Hashing stl.
1. MAPS: 
    Insertion: O(log n)
    Accessing: O(log n)
    Implemented using Red Black trees.

    map<int, int>mp;
    --> mp[0]=2; //similar to dictionary in python.

2. Unordered MAPS: 
    Insertion: O(1)
    Accessing: O(1)
    Deletion: O(n)
    Implemented using Hash Tables(basically array of buckets)

    unordered_map<int, int>mp;

1. Count Frequency of elements in a given Binary Tree:
2. Print vertical order of elements of a Binary Tree:
                10
               /  \
              7    4
             / \   / \
            3  11 14  6 [Note: Here 10, 11 and 14 are in same column]

Answer: 3 7 10 11 14 4 6. where the horizontal distance of 10 11 and 14 from the middle of the array is 0. The distance of 7 is -1 and the distance of 3 is -2. And the distance of 4 is 1 and distance of 6 is 2.

APPROACH: using hashing
1. Starting from root node.
2. Recursively call left and right with (HD-1) and (HD+1) as arguments.
    Base Case: When current node=NULL(return)

We will create a Map in which we use the key's as horizontal distance and for value we use vectors.
and we push the values to the vectors.

2. Count Number of subarrays with sum ZERO:
APPROACH: 
if we go bruteforce then the time Complexity will be O(n^2).
So we have optimised approach.
Compute Prefix sum: Prefix sum is the sum from the begining to to current element.
we have to now find the such indexes which repeat after certain distance. It means that the between elements from the that element to the next index where it repeats returns 0.
So we use combinations here. And from hashing we can calculate the Frequency of such elements.

So, we have: (i) Map prefix sum to a map
            (ii) For every key, choose 2 values from all the occurences of particular prefsum(MC2)
            (iii) Special Case: For prefsum 0,  we have to also include them.

3. TOP K most frequent element
4. Sudoku Solver: Sudoku means 9X9 matrix. You have to solve for the missing elements.

------------------------------------GREEDY ALGORITHM--------------------------------------------
Generally sorting is applied while applying greedy technique.

1. Indian coin change: You are given an array of Denominations and a value X. You need to find the minimum number of coins required to make value X.
NOTE: we have infinite supply of coins.
APPROACH:   1. Start from the largest value, till we can include it, take it.
            2. Else move on the smaller value.

2. Activity selection Problem: You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
APPROACH: Take the next activity which ends first. Sort the activities with respect to end times.

3. Fractional knapsack: You have already done. But this is new one with comparator and lambda function.

4. OPTIMAL MERGE PATTERN: -->very very easy.
You are given n files with their computation times in an array.
Choose/take any two files, add their computation times and append it to the list of computation times.{cost=Sum of computation time}.
Do this until we are left with only one file in the array. We have to do this operation such that we get minimum cost finally.
Given: arr[]={5,2,4,7}, so if we add 5+2 we get 7 and we again add 7+4 we get 11 and then we again add 11 and 7 we get 18. So the final computation time is 7+11+18. we get 36 as our answer. But this is not maximum.
We sort the array. {2,4,5,7}. So after this, 2+4 gives 6, 6+5 gives 11, 11+7 gives 18.
So the final computation time is 6+11+18=35(i.e the minimum).
APPROACH: 
    1. Push all elements to a MinHeap.
    2. Take 2 top elements one by one and add the cost to answer. Push the merged file to the MinHeap.
    3. When single element remains, output the cost.

5. EXPEDI(EXPEDITION): This is a good question to build concept in greedy. (not completed. Can watch the video)

6. Maximum and minimum array difference: easy logic...
You are given an array, A, of n elements. You have to remove exactly n/2 elements from array A and add it to another array B(initally empty).
Find the maximum and minimum values of differences between these two arrays. 
We define the difference between these two arrays as:
sigmaof(abs(A[i]-B[i])) means sum of the difference of all the elements.

IDEA: 
To maximize abs(A[i]-A[j])
1. A[i] should be as large as possible.
2. A[j] should be as small as possible.
For sorted array, 
Max Diff = (A[n-1]-A[0])+(A[n-2]-A[1])...(A[n/2]-A[n/2-1])
         = (A[n-1]+A[n-2]...A[n/2])-(A[0]+A[1]...A[n/2-1])

To minimise abs(A[i]-A[j])
1. The difference should between A[i] and A[j] should be similar so we can get the difference of the adjacent elements.

For sorted Array,
Min Diff = (sum of odd elements)-(sum of even elements)
--------------------------------------GRAPH THEORY-----------------------------------------------
Components of a graph: 
1. Nodes: These are the states or vertex. For instance, users in facebook.
2. Edges: Links between states in a graph. For instance, connections between users.
    - undirected graph: Two way edges.
    - directed graph: One way edges.
3. Representation: 1. Adjacency Matrix: 2D array, where a[i][j]=1 if there is an edge from i to j, else a[i][j]=0
    2. Adjacency List: Array of lists, where each a[i] is a list of nodes Xi, that are reachable from i.

TRAVERSALS: BFS(queue) and DFS(stack).

Terminologies in Graphs: 
1. Adjacent Vertices: Adjacent vertices are two vertices with a direct edge connecting them.
2. Degree of a vertex: There are two types of degree: 
    (i) Indegree: Number of incoming edges to a node.
    (ii) Outdegree: Number of outgoing degree from a node.
3. Connected graph: Each node has path from every other node.
4. Disconnected graph: Each node doesn't have path from every other node.
5. Cycle in a graph.

Tree: Tree is connected acyclic graph.
        Properties of a Tree with n nodes:
        1. Number of edges=n-1
        2. There are no cycles present.
        3. Each node has path from every other vertex.

NUMBER OF EDGES IN A COMPLETE GRAPH: nC2 =(n*(n-1))/2

Graph Representation: 



------------------------------------DYNAMIC PROGRAMMING-------------------------------------------
Properties of Dynamic Programming: 
1. Optimal Substructure: If we can write a recurrence relation, then a problem is said to have optimal substructure.
2. Overlapping Subproblem: If our subproblems repeat, then a problem is said to have overlapping subproblem.
For example: if we have to compute fibonacci of 4. then we can use recurrence relation. And also we have to find fibonacci of some numbers again and again so we don't compute then again. we store and use it. So fibonacci follows both the properties.

Ways to handle Overlapping Subproblem: 
    1. Memoization(Top-Down): A lookup table is maintained and checked before computation of any state. Recursion is involved.

    2. Tabulation(Bottom-Up): Solution is built from base. It is an iterative process.
KEY POINTS: Minimization and maximization problems are generally solved using dp where we want exhaustive solution.   (Sometimes with binary Search on answer).
"Find the number of ways" is also a very popular type of DP problems.
Wherever we can form recurrence relation or given in question can be solved using DP. (Sometimes with matrix Exponentiation).
