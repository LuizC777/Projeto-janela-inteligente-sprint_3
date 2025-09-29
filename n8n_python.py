# Código utilizado no nó "Code" do n8n:

"""  import re

resultado_items = []

for item in items:
    # Recebe a frase do fluxo
    frase = item["json"].get("output", "")
    
    # Extrai o número de energia restante
    match = re.search(r'(\d+)% de energia', frase)
    energia = int(match.group(1)) if match else 0
    
    # Verifica se a energia é suficiente
    energia_suficiente = energia > 75
    
    # Verifica se há referência a chuva
    chuva = "chuva" in frase.lower()
    
    # Define qual HTTP Request será chamado dependendo da chuva
    if energia_suficiente:
        condicao_chuva = not chuva  # True se não houver chuva, False se houver chuva
    else:
        condicao_chuva = None  # energia insuficiente, não executar
    
    # 5️Condição de teste independente do clima (abrir/fechar)
    # True = abrir | False = fechar
    condicao_teste = True  # Alterar para False para testar fechar
    
    # Retorna resultados
    resultado_items.append({
        "json": {
            "energia": energia,
            "energia_suficiente": energia_suficiente,
            "chuva": chuva,
            "condicao_chuva": condicao_chuva,
            "condicao_teste": condicao_teste,
            "mensagem": f"Energia: {energia}% | {'chuva' if chuva else 'sem chuva'} | Teste: {'abrir' if condicao_teste else 'fechar'}"
        }
    })

return resultado_items """
