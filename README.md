# svxlink-automake

EchoLink no Raspberry - Fácil instalação do SVXLINK em sistemas Linux para plataforma embarcada ARM

ATENÇÃO
==============================================================================================================
Este software foi desenvolvido para facilitar o processo de instalação e configuração do SVXLINK (Echolink para Linux) criado por Tobias Blomberg, radioamador com o indicativo SM0SVX.
Este software tem por objetivo, instalar sempre a versão mais recente do SVXLINK no seu dispositivo Pi, otimizando todo o processo de instalação e configuração.
Este software é protegido pela Lei de Direitos Autorais e de Propriedade Intelectual e por tratados internacionais.
Não pode ser vendido ou comercializado. Sua distribuição é gratuita e o código-fonte é disponibilizado sob os termos de licença GNU/Linux 3.0 e distribuíbo exclusivamente pelo site github.com.
Autor: Airam - PU8ASR (airamcosta@gmail.com)
==============================================================================================================

Meu nome é Airam, sou brasileiro e radioamador com o indicativo de minha estação PU8ASR.
Atualmente mantenho um link do Echolink na cidade de Manaus, no coração da floresta amazônica.
Este link está conectado na Conferência Amazônica no Echolink ( *AMAZON* ).
Muito se tem discutido sobre energias renováveis, auto-sustentabilidade e economia de recursos.
E na busca de soluções para economia de energia no meu shack (estação de radioamador), encontrei o Raspberry Pi.
Meu link está trabalhando no Raspberry Pi B + (PU8ASR-L).
No Brasil, infelizmente, há poucos usuários de sistemas com conhecimento / Linux e menos ainda aqueles que usam e mantêm um link com o rádio amador.
Eu acho que deu para você para entender o propósito deste repositório.
Eu quero criar um repositório aqui para então, a partir de uma única linha de comando, qualquer usuário pode iniciar uma instalação guiada e automática, devendo informar poucos dados como INDICATIVO, SENHA para que scripts iniciem o processo de autoinstalar e autoconfigurar tudo, deixando apenas o usuário para realizar as conexões necessárias e usar o link.
Parece estranho fazer algo em paralelo ao svxlink do sm0svx. Nós não competimos e parabenizo o colega de hobby pelos esforços. Eu quero dar uma contribuição sem mudar sua estrutura e talvez mais tarde possamos mesclar tudo, será um benefício mútuo (para todos).
Podemos até inserir esquemas de interfaces neste repositório e o esquema equivamente será baixado de acordo com a escolha do usuário.
Se este projeto despertou interesse em você, entre e ajude a popularizar o Raspberry e o SVXLINK.

Tudo o que é necessário fazer para utilizar o Echolink no Raspberry Pi e/ou em outros modelos da família Pi como Orange, Bannana, dentre outros, são apenas os passos a seguir:
1) Um cartão microSD Card de pelo menos 8GB - Classe 10;
2) Qualquer modelo de Pi;
3) Dongle de áudio USB;
4) Conexão à internet que pode ser feita pelo cabo de rede ou wifi;
5) Imagem do sistema operacional a ser gravado no microSD Card. Recomendável a versão completa - https://www.raspberrypi.org/downloads/raspbian/
6) Software para formatar o microSD Card - https://www.sdcard.org/downloads/formatter_4/eula_windows/
7) Software para gravação da imagem do sistema operacional no microSd Card - https://goo.gl/oIOyuJ
8) Curso completo em vídeo para você entender os passos (Este instalador irá simplificar estes passos) - https://www.youtube.com/playlist?list=PLXMJj8G516Xpd8fiygQuFu_KMF8SIjgKy

Basicamente depois que o sistema operacional estiver gravado no microSD Card e este por sua vez estiver inserido no Raspberry, bem como todos os dispositivos, basta ligá-lo pela primeira vez e após a inicialização, não realize configurações adicionais como idioma, hora, etc.
Acesse o terminal de comandos e digite:
==============================================================================================================
cd /home/pi/Downloads && wget https://github.com/pu8asr/svxlink-automake/raw/master/makefile && make
==============================================================================================================

Se não existir a Pasta Downloads em /home/pi/Downloads ocorrerá um erro e o instalador não será executado. Para corrigir o problema use o comando mkdir /home/pi/Downloads e em seguida repita o comando destacado acima.

Depois é só seguir as etapas da instalação e se o Pi reiniciar, repetir o comando acima.

Após a conclusão da instalação, a configuração do SVXLINK deve ser feita manualmente, por enquanto. Brevemente esperamos automativar tudo.

Acredito que possamos popularizar essa tecnologia e reduzir custos para manter um link no ar 24 horas por dia.
Compartilhe!

Este texto está em Português do Brasil e pretendemos disponibilizar tambem em outros idiomas.
Grupo de discussão oficial sobre Echolink no Raspberry no Whatsapp - https://goo.gl/ZHkPSw

Este instalador simplifica o processo exibido neste cruso em vídeo - https://goo.gl/MGqJ5t
