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
	for(i=0; i<N; i++) { a[i] = (i+1) % N; }
	k = (M+N-1) % N;  // index starts from 0
	j = (k-1+N) % N;

	for(int c=0; c<N; c++) {
		for(int t=1; t<K; t++) { // k is counted to be the first
			j = k;
			k = a[k];
		}
		// k+1 means 1~N
		cout << k+1 << endl;
		a[j] = a[k];
		k = a[k];
	}


	delete[] a;
	a = NULL;

	return 0;
}

