
        hp.erase(remove_if(hp.begin(), hp.end(), [](int x)
                           { return x <= 0; }),
                 hp.end()); // 체력이 0 이하인 SCV 제거