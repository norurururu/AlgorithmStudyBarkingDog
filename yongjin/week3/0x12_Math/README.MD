vector<bool>이 다른 자료형 bool arr[n] 이런거 보다 더 빠르다
배열로 하게되면 하나하나가 1byte로 저장되는데
벡터로 하게되면 하나하나가 1bit로 저장되서
공간도 1/8로 적게 쓰고 cache hit rate도 올라가서
훨씬 빠르다

합성수에서 1을 제외한 가장 작은 약수는 root(n)이하에 존재한다
즉 2부터 root(n)까지의 수로 나누어 지지 않으면 소수이다.

vector.size()를 사용할땐 (int)를 붙여서
(int)vector.size()이렇게 사용하자
안그러면 v.size()-- 하는과정에서 음수가 되면 오버 플로우 발생한다
왜냐하면 v.size()는 signed가 아니라 unsigned이기 때문이다