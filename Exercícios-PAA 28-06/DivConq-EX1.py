def potenciacao(num: int, power: int) -> int:
    if power == 0: 
        return 1
    elif power == 1:
        return num
    elif power & 1 == 0: 
        return potenciacao(num * num, power // 2)
    elif power & 1 == 1: 
        return num * potenciacao(num * num, (power - 1) // 2)

def main():
    num, power = map(int, input("Digite dois números em sequência: ").split())
    print(potenciacao(num, power))

if __name__ == "__main__":
    main()