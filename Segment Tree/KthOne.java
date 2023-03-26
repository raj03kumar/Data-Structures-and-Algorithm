import java.io.*;
import java.util.*;

public class KthOne {
    public static int N = 100002;
    public static int[] a = new int[N];
    public static int[] tree = new int[4*N];

    public static void build(int node, int st, int en){
        if(st == en){
            tree[node] = a[st];
            return;
        }
        int mid = (st+en)/2;
        build(2*node, st, mid);
        build(2*node+1, mid+1, en);

        tree[node] = tree[2*node]+tree[2*node+1];
    }

    public static void update(int node, int st, int en, int idx){
        if(st == en){
            if(a[st] == 0){
                a[st] = 1;
                tree[node] = 1;
            }
            else{
                a[st] = 0;
                tree[node] = 0;
            }
            return;
        }
        int mid = (st+en)/2;
        if(idx<=mid){
            update(2*node, st, mid, idx);
        }
        else{
            update(2*node+1, mid+1, en, idx);
        }
        tree[node] = tree[2*node] + tree[2*node+1];
    }

    // descending the segment tree
    public static int query(int node, int st, int en, int k){
        if(st == en) return st;

        int mid = (st+en)/2;

        if(k < tree[2*node]) return query(2*node, st, mid, k);
        else return query(2*node+1, mid+1, en, k-tree[2*node]);
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        for(int i=0; i<n; i++){
            a[i] = sc.nextInt();
        }
        build(1, 0, n-1);

        for(int i=0; i<m; i++){
            int type = sc.nextInt();
            if(type == 1){
                int idx = sc.nextInt();
                update(1, 0, n-1, idx);
            }
            else{
                int k = sc.nextInt();
                int ans = query(1, 0, n-1, k);
                System.out.println(ans);
            }
        }
    }
}

/*
INPUT:
5 7
1 1 0 1 0
2 0
0 <-- output
2 1
1 <-- output
2 2
3 <-- output
1 2
2 3
3 <-- output
1 0
2 0
1 <-- output
*/