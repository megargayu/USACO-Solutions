#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("rental.in", "r", stdin);
	int n, m, r;
	cin >> n >> m >> r;

	vector<int> milk_amt(n);
	for (int i = 0; i < n; i++) {
		cin >> milk_amt[i];
	}

	vector<pair<int, int>> shops(m);
	for (int i = 0; i < m; i++) {
		cin >> shops[i].second >> shops[i].first;
	}

	vector<int> rent(r);
	for (int i = 0; i < r; i++) {
		cin >> rent[i];
	}

	// sort cows by milk production in descending order
	sort(milk_amt.begin(), milk_amt.end(), greater<int>());
	// sort shops by selling price in descending order
	sort(shops.begin(), shops.end(), greater<pair<int, int>>());
	// sort rent in descending order
	sort(rent.begin(), rent.end(), greater<int>());

	int shop_at = 0;  // the index of the shop which we've bought up to
	int rent_at = 0;  // the index of the farmer we've rented up to
	int cow_at = 0;
	long long max_money = 0;
	while (cow_at < n) {
		int amt = milk_amt[cow_at];
		int sold_money = 0;  // how much we can make from selling the milk
		int curr_shop = shop_at;
		int last = 0;

		// calculate how much money this cow can make if we sell its milk
		while (curr_shop < m) {
			int sold = min(amt, shops[curr_shop].second);
			sold_money += shops[curr_shop].first * sold;
			amt -= sold;

			if (amt == 0) {
				last = sold;
				break;
			} else {
				curr_shop++;
			}
		}

		// should we rent or sell this cow?
		if (rent_at >= r || sold_money > rent[rent_at]) {
			max_money += sold_money;
			shop_at = curr_shop;
			if (shop_at < m) {
				shops[shop_at].second -= last;
			}
			cow_at++;
		} else {
			max_money += rent[rent_at];
			/*
			 * instead of renting this cow, it's better to rent off
			 * the cow that makes the least amount of milk
			 * (we don't process the cow at the end of the list)
			 */
			n--;
			rent_at++;
		}
	}

	//freopen("rental.out", "w", stdout);
	cout << max_money << endl;
}
