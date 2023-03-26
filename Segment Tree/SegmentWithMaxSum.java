import java.io.*;
import java.util.*;

public class SegmentWithMaxSum{
    public static class grp{
        public long pref, suff, sum, ans;
        grp(long pref, long suff, long sum, long ans){
            this.pref=pref;
            this.suff=suff;
            this.sum=sum;
            this.ans=ans;
        }
    }
    public static int N = 100002;
    public static long []a = new long[N];
    public static grp []tree = new grp[4*N];
    public static void build(int node, int st, int en){
        if(st==en){
            if(a[st]<=0){
                tree[node]=new grp(0, 0, a[st], 0);
            }
            else{
                tree[node]=new grp(a[st], a[st], a[st], a[st]);
            }
            return;
        }
        int mid = (st+en)/2;
        build(2*node, st, mid);
        build(2*node+1, mid+1, en);

        long sum = tree[2*node].sum +tree[2*node+1].sum;
        long pref = Math.max(tree[2*node].pref, tree[2*node].sum+tree[2*node+1].pref);
        long suff = Math.max(tree[2*node+1].suff, tree[2*node+1].sum+tree[2*node].suff);
        long ans = Math.max(tree[2*node].suff+tree[2*node+1].pref, Math.max(tree[2*node].ans, tree[2*node+1].ans));

        tree[node] = new grp(pref, suff, sum, ans);
    }
    public static void update(int node, int st, int en, int idx, long val){
        if(st == en){
            a[st]=val;
            if(a[st]<=0){
                tree[node]=new grp(0, 0, a[st], 0);
            }
            else{
                tree[node]=new grp(a[st], a[st], a[st], a[st]);
            }
            return;
        }

        int mid = (st+en)/2;
        if(idx<=mid){
            update(2*node, st, mid, idx, val);
        }
        else{
            update(2*node+1, mid+1, en, idx, val);
        }
        long sum = tree[2*node].sum +tree[2*node+1].sum;
        long pref = Math.max(tree[2*node].pref, tree[2*node].sum+tree[2*node+1].pref);
        long suff = Math.max(tree[2*node+1].suff, tree[2*node+1].sum+tree[2*node].suff);
        long ans = Math.max(tree[2*node].suff+tree[2*node+1].pref, Math.max(tree[2*node].ans, tree[2*node+1].ans));

        tree[node] = new grp(pref, suff, sum, ans);
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        for(int i=0; i<n; i++){
            a[i]=sc.nextInt();
        }
        build(1, 0, n-1);
        System.out.println(tree[1].ans);
        for(int i=0; i<m; i++){
            int idx = sc.nextInt();
            long val = sc.nextInt();
            update(1, 0, n-1, idx, val);
            System.out.println(tree[1].ans);
        }
    }
}

/*
INPUT:
5 2
5 -4 4 3 -5
8 <-- OUTPUT
4 3
11 <--OUTPUT
3 -1
7 <-- OUTPUT
*/