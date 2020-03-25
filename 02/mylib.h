using On = void (*)(const std::string);
using At = void (*)();
using num = void (*)(int);
void register_on_string(On);
void register_first(At);
void register_end(At);
void register_on_number(num);
void parse(const char *);
