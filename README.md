<h1 align="center">
cpp-url-decode
</h1>

C++ URL percent decoding header only library

## Usage

```cpp
#include <iostream>

#include "url_decode.hpp"

int main() {
    std::cout << url::decode("Hello%20world") << std::endl;
    return 0;
}
```
