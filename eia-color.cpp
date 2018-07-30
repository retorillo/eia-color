#include "eia-color.h"

int main() {
  static std::array<std::string, 10> names
    = { "Black", "Brown", "Red", "Orange", "Yellow", "Green", "Blue", "Violet", "Grey", "White" };
  static std::array<std::string, 10> codes
    = { "BK", "BR", "RD", "OG", "YE", "GN", "BU", "VT", "GY", "WH" };

  static bool reverse = false;
  static std::random_device R;

  static auto H = []() {
    std::cout << std::endl;
    std::cout << "  ______ _____             _____ ____  _      ____  _____  " << std::endl;
    std::cout << " |  ____|_   _|   /\\      / ____/ __ \\| |    / __ \\|  __ \\ " << std::endl;
    std::cout << " | |__    | |    /  \\    | |   | |  | | |   | |  | | |__) |" << std::endl;
    std::cout << " |  __|   | |   / /\\ \\   | |   | |  | | |   | |  | |  _  / " << std::endl;
    std::cout << " | |____ _| |_ / ____ \\  | |___| |__| | |___| |__| | | \\ \\ " << std::endl;
    std::cout << " |______|_____/_/    \\_\\  \\_____\\____/|______\\____/|_|  \\_\\" << std::endl;
    std::cout << std::endl;
    std::cout << "             EIA COLOR CODE TRAINING PROGRAM"  << std::endl;
    std::cout << "    AUTHORED BY RETORILLO  /  NO RIGHTS RESERVED (CC0)" << std::endl;
    std::cout << std::endl;
    std::cout << "               HELP: THIS HELP SCREEN"      << std::endl;
    std::cout << "               MODE: TOGGLE TRAINING MODES" << std::endl;
    std::cout << "               EXIT: EXIT PROGRAM"          << std::endl;
    std::cout << std::endl;
    std::cout << (!reverse ? "NAME => NUMBER OR CODE" : "NUMBER => CODE OR NAME") << std::endl;
    std::cout << std::endl;
  };
  static auto Q = []() {
    std::string answer;
    int q_i = round((R() / static_cast<double>(std::random_device::max() - std::random_device::min())
    + std::random_device::min()) * (names.size() - 1));
    std::cout << (!reverse ? names[q_i] : std::to_string(q_i)) << " => ";
    std::getline(std::cin, answer);
    answer = tolower(answer);
    if (answer == "exit") return false;
    if (answer == "help") { H(); return true; }
    if (answer == "mode") { reverse = !reverse; H(); return true; }

    if (!reverse) {
      int answer_i;
      try {
        answer_i = std::stoi(answer);
        if (answer_i != q_i)
          std::cout << "!! " << q_i << " !!" << std::endl;
        return true;
      }
      catch (const std::invalid_argument& e) { }
      catch (const std::out_of_range& e) { }

      if (tolower(answer) != tolower(codes[q_i])) {
          std::cout << "!! " << codes[q_i] << " !!" << std::endl;
          return true;
      }
    }
    else {
      static auto compare = [&answer](std::string n) { return tolower(answer) == tolower(n); };
      if (answer.size() == 2) {
        auto match_code = std::find_if(codes.begin(), codes.end(), compare);
        if (match_code == codes.end() || *match_code != codes[q_i])
          std::cout << "!! " << codes[q_i] << " !!" << std::endl;
      }
      else {
        auto match_name = std::find_if(names.begin(), names.end(), compare);
        if (match_name == names.end() || *match_name != names[q_i])
          std::cout << "!! " << names[q_i] << " !!" << std::endl;
      }
    }
    return true;
  };

  H();
  while (Q()) continue;
}

std::string tolower(std::string a){
  std::string clone = a.substr();
  static auto tolower = [](char ch) { return std::tolower(ch); };
  std::transform(clone.begin(), clone.end(), clone.begin(), tolower);
  return clone;
}
