# 🎲 Dice Rolling Game - C++

An interactive console-based dice rolling game with a scoring system and achievements.

## 📋 Features
- Random dice generation (1-6)
- Visual ASCII dice display
- Special combination detection (Snake Eyes, Lucky Seven, Doubles, etc.)
- Dynamic scoring system with multipliers
- Achievement unlocking system
- Real-time statistics tracking

## 🎮 How to Play
1. Press ENTER to roll two dice
2. Earn points based on your roll
3. Get bonus points for special combinations
4. Unlock achievements as you play
5. Try to achieve the highest score!

## 🛠️ How to Run

### Windows (PowerShell or CMD)
```bash
g++ dice_game.cpp -o dice_game
.\dice_game.exe
```

### Mac/Linux
```bash
g++ dice_game.cpp -o dice_game
./dice_game
```

## 📚 Concepts Used
- **C++ Basics**: Variables, operators, data types
- **Functions**: Modular programming
- **Arrays**: 2D string arrays for dice patterns
- **Loops**: Game continuation logic
- **Conditionals**: Game rules and scoring
- **Random Generation**: Dice simulation

## 📦 Libraries Used
- `<iostream>` - Input/output operations
- `<cstdlib>` - Random number generation
- `<ctime>` - Time-based seeding
- `<iomanip>` - Formatted output
- `<string>` - String operations
- `<limits>` - Input buffer management

## 🎯 Special Combinations
- **Snake Eyes** (1,1) - Consolation prize
- **Doubles** - 2x points multiplier
- **Lucky Seven** (sum = 7) - +7 bonus
- **Yo-Leven** (sum = 11) - +11 bonus
- **Boxcars** (6,6) - 2x points + 10 bonus

## 🏆 Achievements
- **Veteran Roller** - Roll 10+ times
- **Doubles Master** - Get 3+ doubles
- **Lucky Charm** - Roll 2+ lucky sevens
- **High Scorer** - Reach 100+ points

## 📸 Screenshot
<img width="361" height="639" alt="image" src="https://github.com/user-attachments/assets/30147d00-8391-4e16-9104-0b803d15d866" />
<img width="433" height="343" alt="image" src="https://github.com/user-attachments/assets/59c663ad-23c9-474b-be01-6e1896b12c8b" />


## 👨‍💻 Author
Talha Khan

## 📄 License
This project is open source and available for learning purposes.
