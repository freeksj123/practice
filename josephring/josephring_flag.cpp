#include <iostream>

using namespace std;

int main()
{
	int N, M, K;

	while(1) {
		cout << "Please input N:" << endl;
		cin >> N;
		if(N<1) { cout << "N=" << N << " is too small" << endl; }
		else { break; }
	}

	while(1) {
		cout << "Please input M:" << endl;
		cin >> M;
		if(M<1) { cout << "M=" << M << " is not good" <<  endl; }
		else { break; }
	}

	while(1) {
		cout << "Please input K:" << endl;
		cin >> K;
		if(K<1) { cout << "K=" << K << " is not good" << endl; }
		else { break; }
	}

	int *a = NULL;
	a = new int[N];

	int i, j, k;
	for(i=0; i<N; i++) { a[i] = 1; }
	k = (M+N-1) % N;  // index starts from 0
	j = 1;

	for(int c=0; c<N; c++) {
		while(j<K) { // k is counted to be the first
			k = (k+1) % N;
			j += a[k];
		}
		cout << k+1 << endl; // k+1 means 1~N
		a[k] = 0;
		j = 0;
	}


	delete[] a;
	a = NULL;

	return 0;
}

