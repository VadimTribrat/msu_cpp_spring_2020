using On = void (*)(char *);
using At = void (*)();
void register_on_string(On);
void register_first(At);
void register_end(At);
void register_on_number(On callback);
void parse(const char *);
