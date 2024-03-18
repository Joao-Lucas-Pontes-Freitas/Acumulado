import pandas as pd

def read_columns_from_excel(file_path, sheet_name=0):
    df = pd.read_excel(file_path, sheet_name=sheet_name)
    columns = [df[col].tolist() for col in df.columns]
    return columns

# Exemplo de uso:
file_path = 'Akinator.txt.xlsx'
columns = read_columns_from_excel(file_path)
campos = ["nome","droid","humano","alien","jedi","sith","filme","serie","politico","clone","rebelde","mandaloriano","imperial","morto","defeituoso","militar","entendivel","corpo incompleto","grupo","renegado","2 caras","genio","piloto","crianca/adolescente","cacador"]



database = []
for j in range(45):
  dic = {}
  for i in range(25):
    dic[campos[i]] = columns[i][j]
  database.append(dic)
# print(database)

def take_chance(answer, property):
    if answer == "y":
        ans = True
    else:
        ans = False

    to_remove = []
    for d in database:
        if d[property] != ans:
            to_remove.append(d)

    for i in to_remove:
        database.remove(i)

    if len(database) == 1:
        print("\nyour character is "+database[0]["nome"])
        exit()


print(database)


print("Akinator STAR WARS\n")

ans = input("É droid? (y/n) ")
take_chance(ans, "droid")

ans = input("É humano? (y/n) ")
take_chance(ans, "humano")

ans = input("É alien? (y/n) ")
take_chance(ans, "alien")

ans = input("É/Foi jedi? (y/n) ")
take_chance(ans, "jedi")

ans = input("É/Foi sith? (y/n) ")
take_chance(ans, "sith")

ans = input("Esteve em filme? (y/n) ")
take_chance(ans, "filme")

ans = input("Esteve em serie? (y/n) ")
take_chance(ans, "serie")

ans = input("É/Foi politico? (y/n) ")
take_chance(ans, "politico")

ans = input("É clone? (y/n) ")
take_chance(ans, "clone")

ans = input("É/Foi rebelde? (y/n) ")
take_chance(ans, "rebelde")

ans = input("É mandaloriano? (y/n) ")
take_chance(ans, "mandaloriano")

ans = input("É/Foi imperial? (y/n) ")
take_chance(ans, "imperial")

ans = input("Morto em tela? (y/n) ")
take_chance(ans, "morto")

ans = input("É defeituoso? (y/n) ")
take_chance(ans, "defeituoso")

ans = input("É militar? (y/n) ")
take_chance(ans, "militar")

ans = input("É entendível? (y/n) ")
take_chance(ans, "entendivel")

ans = input("Tem corpo incompleto? (y/n) ")
take_chance(ans, "corpo incompleto")

ans = input("Faz parte de um grupo? (y/n) ")
take_chance(ans, "grupo")

ans = input("Foi exilado ou se revoltouw (y/n) ")
take_chance(ans, "renegado")

ans = input("É 2 caras? (y/n) ")
take_chance(ans, "2 caras")

ans = input("É genio? (y/n) ")
take_chance(ans, "genio")

ans = input("É piloto? (y/n) ")
take_chance(ans, "piloto")

ans = input("Aparece como criança/adolescente? (y/n) ")
take_chance(ans, "crianca/adolescente")

ans = input("É/Foi caçador de recompensas? (y/n) ")
take_chance(ans, "cacador")



