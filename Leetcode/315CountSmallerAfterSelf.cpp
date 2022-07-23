#include <bits/stdc++.h>
using namespace std;

ostream& operator<<(ostream& os, const vector<int>& a) {
  for (int x : a) cout << x << " ";
  return os;
}

class MergeSort {
  private:
  int n;

  vector<int> res;
  vector<vector<int>> c;
  vector<vector<int>> a;

  void merge(int l, int mid, int r) {
    int i = l, j = mid+1;
    int n = mid, m = r;

    int k = 0, len = 0;
    while (i <= n && j <= m) {
      while (j <= m && a[j][0] < a[i][0]) {
        len++;
        c[k++] = a[j++];
      }

      res[a[i][1]] += len;
      c[k++] = a[i++];
    }

    while (i <= n) {
      res[a[i][1]] += len;
      c[k++] = a[i++];
    }

    while (j <= m) {
      c[k++] = a[j++];
    }

    for (i=0; i<k; i++) {
      a[i+l] = c[i];
    }
  }

  void mergeSort(int l, int r) {
    if (l < r) {
      int mid = (l + r)/2;

      mergeSort(l, mid);
      mergeSort(mid+1, r);
      merge(l, mid, r);
    }
  }

  public:
  MergeSort(int n) {
    this->n = n;

    res = vector<int>(n);
    c = vector<vector<int>>(n, vector<int>(2));
    a = vector<vector<int>>(n, vector<int>(2));
  }

  void set(vector<int>& b) {
    for (int i=0; i<n; i++) {
      a[i] = { b[i], i };
    }
  }

  vector<int> get() {
    mergeSort(0, n-1);
    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("error.txt", "w", stderr);
  freopen("output.txt", "w", stdout);
  #endif

  vector<int> a = {5, 2, 8, 1, 6, 5, 3};

  int n = a.size();

  MergeSort obj(n);
  obj.set(a);

  vector<int> res = obj.get();
  cout << res;

  return 0;
}