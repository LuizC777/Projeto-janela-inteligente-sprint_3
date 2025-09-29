# Projeto janela inteligente
---

Membros:

Raphael Talarico Rm 565219

Luiz Claro Rm 563014

Gabriel Romão Rm 563378

Mateus Patrício Pereira Rm 564695

Leonardo Luster Gomes Rm 564448

Gabriel Nacarelli Pinheiro Rm 565298

---

# Integração dos Componentes do Projeto de Janela Inteligente

O projeto de janela inteligente foi desenvolvido para automatizar o fechamento de uma janela com base em condições climáticas específicas, além de permitir o controle manual por meio de uma interface de inteligência artificial via Telegram. A integração dos componentes foi cuidadosamente planejada para garantir uma operação eficiente, segura e responsiva.

## Componentes Principais

- **ESP-32 com servo-motor:** O ESP-32 é o microcontrolador responsável por executar o comando físico de fechar ou abrir a janela, acionando o servo-motor conectado. O servo-motor atua diretamente na janela, realizando o movimento de fechamento ou abertura conforme instruído.
  
- **Telegram e agente de IA:** A comunicação do usuário com o sistema ocorre via Telegram. O usuário pode enviar comandos manuais para o agente de IA, que processa as solicitações e determina as ações a serem tomadas.

- **Workflow controlado pelo n8n com código Python:** O n8n funciona como a plataforma de orquestração do fluxo de trabalho. Ele integra a lógica do projeto, executando scripts em Python que processam as informações recebidas e coordenam as ações entre os diferentes componentes.

- **APIs externas:** O sistema utiliza duas APIs fundamentais para a tomada de decisão:
  - API de clima, que fornece dados atualizados sobre a previsão do tempo, incluindo possibilidade de chuva.
  - API de verificação de energia, que monitora o nível de energia disponível nos equipamentos para assegurar que haja energia suficiente para acionar o servo-motor.

## Fluxo de Funcionamento

1. **Início do workflow pelo Telegram:** O usuário envia uma mensagem via Telegram para o agente de IA, que é o ponto de entrada para o controle manual ou automático da janela.

2. **Processamento pela IA e APIs:** O agente de IA utiliza um modelo da OpenAI para interpretar o comando do usuário e consulta as APIs externas para obter dados em tempo real sobre as condições climáticas e o status energético dos equipamentos.

3. **Análise e decisão:** Com as informações coletadas, o sistema avalia se há risco de chuva e se o sistema possui energia suficiente para executar a ação. Essa decisão é feita dentro do workflow no n8n, com a lógica implementada em Python.

4. **Comando ao ESP-32:** Caso as condições indiquem que a janela deve ser fechada (seja automaticamente por risco de chuva ou manualmente pelo usuário), o workflow envia um comando ao ESP-32.

5. **Atuação do servo-motor:** O ESP-32 recebe o comando e aciona o servo-motor para fechar ou abrir a janela conforme necessário.

## Benefícios da Integração

A integração entre o hardware (ESP-32 e servo-motor), as plataformas de comunicação (Telegram e IA), o workflow orquestrado pelo n8n e as APIs externas resulta em um sistema inteligente, capaz de responder rapidamente a mudanças ambientais e demandas do usuário, garantindo a proteção do ambiente e o uso eficiente de recursos energéticos.
