//#include <iostream>
//
//using namespace std;
//typedef struct testStruct
//{
//	int a = 1;
//	double b = 2;
//	unsigned long c = 3;
//} test, *ptest;
//
//int main() {
//	unsigned long begin = ((0x00000800 + 0x100) + 0x096);
//	unsigned long type = (0x00001000 + 330) + 76;
//	unsigned long end = ((0x00000800 + 0x100) + 0x096) + 300;
//	type &= ~0x8000000;
//	cout << begin <<  endl;
//	cout << type << endl;
//	cout << end << endl;
//	return 0;
//}
#include <iostream>
#include <bitset>
#include <vector>
#include <string>
#include <cstring> // 用于memcpy
#include<thread>
#include<mutex>
#include <iterator>
#include <random>
#include<unordered_map>

int64_t FourToTen(std::string& strRes) {

	int64_t i64RoundsResultVal = 4422384613159032669;

	//std::cout << strRes.size() << std::endl;
	while (i64RoundsResultVal > 0)
	{
		int remainder = i64RoundsResultVal % 4;
		strRes = std::to_string(remainder) + strRes;
		i64RoundsResultVal >>= 2;
	}

	///*if (strRes.size() >= 32) {
	//	strRes.erase(0, 1);
	//}*/
	////将本局结果添加进去
	//i64RoundsResultVal = 0;
	//strRes += std::to_string(3);
	/*for (int i = 0; i < strRes.size(); i++) {
		int num = strRes[i] - '0';
		i64RoundsResultVal += num * pow(4, (strRes.size() - i - 1));
	}*/
	//strRes += std::to_string(3);

		/*std::string str1 = "1131331313313333133333311333";
		std::string str2 = "1131331313313333133333312000";*/
	std::cout << strRes.size() << std::endl;
	i64RoundsResultVal = strtoull(strRes.c_str(), nullptr, 4);
	if (strRes.size() >= 31) {
		strRes.erase(0, 1);
	}
	strRes += std::to_string(1);
	i64RoundsResultVal = strtoull(strRes.c_str(), nullptr, 4);
	//float a 
	/*int64_t strA1 = strtoull(strRes.c_str(),nullptr, 4);
	int64_t a2 = strtoull(str1.c_str(), nullptr, 4);
	int64_t a3 = strtoull(str2.c_str(), nullptr, 4);
	std::cout << strA1 << std::endl;
	std::cout << a2 << std::endl;
	std::cout << a3 << std::endl;*/
	//int64_t temp = i64RoundsResultVal;
	/*int64_t int64Number = 15030279639;
	printf("%lld", int64Number);
	int q = 0;
	int sof = sizeof(q);*/
	//m_pPlayerInfo->i64IslandPlayerHisResData = i64RoundsResultVal;
	return i64RoundsResultVal;
}

void test() {

	//double num1 =4.6;
	////int num2 = 100;
	//std::cout << (num1 * 100) << std::endl;
	std::string strTest1 = "13214323";
	std::string strTest2;
	strTest2 = strTest1;
	char ch[1024] = { 0 };
	memcpy(&ch, strTest1.c_str(), strTest1.length());
	std::cout << ch << std::endl;
	return;
}

std::mutex mtx; 

void print_block(int n, char c) {
	//std::lock_guard<std::recursive_mutex>lock(mtx);
	std::lock_guard<std::mutex>lock(mtx);
	for (int i = 0; i < n; ++i) {
		std::cout << c;
	}
	std::cout << '\n';
	//mtx.unlock(); // 释放锁
}

void recursive_function() {
	//mtx.lock();
	//std::lock_guard<std::recursive_mutex>lock(mtx);
	//std::lock_guard<std::mutex>lock(mtx);
	std::cout << "Locked by recursive function.\n";
	print_block(10, '#'); // 再次获取锁
	//mtx.unlock();
}

//template<typename T>
//std::pair<const typename T::key_type, typename T::mapped_type> getRandomElement(const T& container) {
//	// 创建一个随机数生成器
//	std::random_device rd;
//	std::mt19937 gen(rd());
//	std::uniform_int_distribution<> distrib(0, container.size() - 1);
//
//	// 选择一个随机的索引
//	size_t randomIndex = distrib(gen);
//
//	// 创建一个指向unordered_map开始的迭代器
//	auto it = container.begin();
//
//	// 移动迭代器到随机索引的位置
//	std::advance(it, randomIndex);
//
//	// 返回迭代器指向的元素
//	return *it;
//}

#include <iostream>
#include <unordered_map>
#include <vector>
#include<algorithm>
#include<functional>
#include<utility>
#include<map>
class test1 {
public:
	test1();
	~test1();
private:
	int n;
};
test1::test1() {
	n = 0;
}

test1::~test1() {

}

test1*testDelete() {
	test1* num = new test1;
	return num;
}

std::pair<int, std::vector<int>> SelectRandomElement(const std::unordered_map<int, std::vector<int>>& starTableInfo) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(0, starTableInfo.size() - 1);
	size_t randomIndex = distrib(gen);
	auto it = std::begin(starTableInfo);
	std::advance(it, randomIndex);
	return *it;
}
//int main() {
//	//int n = 100;
//	//std::unordered_map<int, int*> um;
//	//um[1] = new int(100); // 使用 new 分配内存
//
//	//// 创建一个要删除的键的列表
//	//std::vector<int> keysToDelete;
//	//for (const auto& pair : um) {
//	//	keysToDelete.push_back(pair.first);
//	//}
//
//	//// 遍历这个列表并删除元素
//	//for (int key : keysToDelete) {
//	//	int* value = um[key];
//	//	um.erase(key);
//	//	delete value; // 释放指针指向的内存
//	//}
//	//test1* num = testDelete();
//	//std::unordered_map<int, test1*>m;
//	//m.emplace(1, num);
//	//for (auto it = m.begin(); it != m.end();) {
//	//	delete it->second;
//	//	it->second = nullptr;
//	//	// 删除迭代器元素先加加再删，否则迭代器失效程序崩溃！！！(必须iter++不可以++iter)
//	//	m.erase(it++);
//	//}
//	//std::vector<int*>vec;
//	////for (int i = 0; i < 10; i++) {
//	//	
//	////}
//	////vec.push_back(new int(10));
//	////vec.push_back(new int(7));
//	////vec.push_back(new int(8));
//	//for (auto &v : vec) {
//	//	std::swap(v, vec.back());
//	//	vec.back() = nullptr;
//	//	vec.pop_back();
//	//}
//	/*std::map<int, int>mTest;
//	mTest[1] = 2;
//	mTest[1] = 3;
//	for (auto &it : mTest) {
//		std::cout << it.first << " ：" << it.second << std::endl;
//	}
//	std::unordered_map<int, int>umapTest;
//	umapTest[1] = 1;
//	umapTest[1] = 2;
//	for (auto &it : umapTest) {
//		std::cout << it.first << " ：" << it.second << std::endl;
//	}*/
//	/*std::unordered_map<int, std::vector<int>> starTableInfo;
//	std::vector<int>vec = { 1 };
//	starTableInfo[1] = vec;
//	SelectRandomElement(starTableInfo);*/
//
//	//int nWinScore = -10;
//	//int nLife = 9;
//	///*if (nLife < abs(nWinScore)) {
//	//	nWinScore = -nLife;
//	//}*/
//	//nWinScore = nLife < abs(nWinScore) ? -nLife : nWinScore;
//
//
//
//
//	return 0;
//}

#include <iostream>
#include <ctime>
#include<vector>
#include<functional>
#include<algorithm>

//int add(int a)
//{
//	std::cout << ++a << " ";
//	return a;
//}
//int decrease(int a)
//{
//	std::cout << --a << std::endl;
//	return a;
//}
//
//int main() {
//	int arr[5] = { 1,5,4,8,6 };
//	std::function<int(int a, int b)>cmp = [&](int a, int b)
//	{
//		return a > b;
//	};
//	sort(arr,arr + 5, cmp);
//	for (int i = 0; i < 5; i++)
//		std::cout << arr[i] << "";
//	return 0;
//}

//typedef int(*CallbackFunction)(int);
//
//int processValue(int num, CallbackFunction callback)
//{
//	return callback(num);
//}
//
//int addTen(int num)
//{
//	return num + 10;
//}
//
//int multiplyByTwo(int num) {
//	return num * 2;
//}
//
//void ReplacePathString(const std::string& astrSrc, const std::string& astrReplaceString, std::string& astrResult)
//{
//	astrResult = astrSrc;
//	std::size_t pos = astrResult.find_last_of("\\");
//	astrResult = astrResult.substr(0, pos);
//	astrResult += astrReplaceString;
//
//}
//
//
//void print(int a, int b) {
//	std::cout << "a: " << a << ", b: " << b << std::endl;
//}
//
//int main() {
//	auto boundPrint = std::bind(print, std::placeholders::_1, 20);
//	boundPrint(10); // 输出: a: 10, b: 20
//	return 0;
//}
using namespace std;
class Chops {
public:
	virtual string getDesc()const = 0;
	virtual ~Chops(){}
};

class WoodenChopstick :public Chops {
public:
	string getDesc()const override {
		return "一双木头筷子";
	}
};

class StainlessSteelChopstick :public Chops {
public:
	string getDesc()const override {
		return "一双不锈钢筷子";
	}
};

class StonyChopstick :public Chops {
public:
	string getDesc()const override {
		return "一双石头筷子";
	}
};

class ChopstickFactory {
public:
	static Chops*createChopstick(string type) {
		if (type == "wooden") {
			return new WoodenChopstick();
		}
		else if (type == "stainless"){
			return new StainlessSteelChopstick();
		}
		else if (type == "stony") {
			return new StonyChopstick();
		}
		else {
			return nullptr;
		}
	}
};

int main() {
	Chops*chopstick = ChopstickFactory::createChopstick("wooden");
	if (chopstick) {
		cout << chopstick->getDesc() << endl;
		delete chopstick;
	}
	return 0;
}