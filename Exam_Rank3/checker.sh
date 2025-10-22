#!/bin/bash
#
# ╔════════════════════════════════════════════════════════════════╗
# ║                     💻 Cyberpunk 42 TESTER                      ║
# ║   Aesthetic automated tester — mantém TODOS os testes originais ║
# ╚════════════════════════════════════════════════════════════════╝
#
# Pixel art "TESTER" + theme: roxo / ciano / verde neon
#

# --------------------------
# Configuração e constantes
# --------------------------
FUNCOES=(
    "broken_gnl"
    "filter"
    "scanf"
    "n_queens"
    "permutations"
    "powerset"
    "rip"
)

BIN_DIR="_tests_bin"

# Cores (Cyberpunk feel)
PURPLE='\033[1;35m'
CYAN='\033[1;36m'
GREEN='\033[1;92m'
MAGENTA='\033[1;95m'
YELLOW='\033[1;33m'
RED='\033[1;31m'
BOLD='\033[1m'
NC='\033[0m' # Reset

# --------------------------
# Funções utilitárias
# --------------------------
cleanup() {
    rm -rf "$BIN_DIR"
    rm -f /tmp/output_actual /tmp/output_expected /tmp/test_input /tmp/test_file* /tmp/*_sorted /tmp/compile_errors /tmp/gnl_err
}

# Executa um teste de linha única
# $1: comando (string)
# $2: saída esperada (string)
run_test() {
    local command="$1"
    local expected="$2"
    
    timeout 2s sh -c "$command" > /tmp/output_actual 2>/dev/null
    local exit_code=$?
    
    if [ $exit_code -ne 0 ]; then
        if [ $exit_code -eq 124 ]; then
            echo -e "${RED} (TIMEOUT)${NC}" 1>&2
        elif [ $exit_code -eq 139 ]; then 
            echo -e "${RED} (SEG FAULT)${NC}" 1>&2
        elif [ $exit_code -eq 127 ]; then 
            echo -e "${RED} (RUNTIME ERROR: 127 - Permissão/Binário)${NC}" 1>&2
        else 
            echo -e "${RED} (RUNTIME ERROR: $exit_code)${NC}" 1>&2
        fi
        return 1
    fi

    echo -n "$expected" > /tmp/output_expected

    if ! diff /tmp/output_actual /tmp/output_expected > /dev/null; then
        return 1
    fi
    return 0 
}

# Executa teste de saída multi-linha, ordenando antes de comparar
# $1: comando
# $2: saída esperada (com \n)
# $3: nome do teste (debug)
run_multi_test() {
    local command="$1"
    local expected_output="$2"
    local test_name="$3"
    
    timeout 2s sh -c "$command" | sort > /tmp/output_actual_sorted 2>/dev/null
    local exit_code=$?

    echo -e "$expected_output" | sort > /tmp/output_expected_sorted

    if [ $exit_code -ne 0 ]; then
        return 1
    fi

    if ! diff /tmp/output_actual_sorted /tmp/output_expected_sorted > /dev/null; then
        DEBUG_FAIL_MSG="Falha no ${test_name}"
        return 1
    fi
    return 0
}

# --------------------------
# Pixel art e cabeçalho
# --------------------------
print_header() {
    local lines=(
"▄▄▄█████▓   ▓█████      ██████    ▄▄▄█████▓   ▓█████     ██▀███  "
"▓  ██▒ ▓▒   ▓█   ▀    ▒██    ▒    ▓  ██▒ ▓▒   ▓█   ▀    ▓██ ▒ ██▒"
"▒ ▓██░ ▒░   ▒███      ░ ▓██▄      ▒ ▓██░ ▒░   ▒███      ▓██ ░▄█ ▒"
"░ ▓██▓ ░    ▒▓█  ▄      ▒   ██▒   ░ ▓██▓ ░    ▒▓█  ▄    ▒██▀▀█▄  "
"  ▒██▒ ░    ░▒████▒   ▒██████▒▒     ▒██▒ ░    ░▒████▒   ░██▓ ▒██▒"
"  ▒ ░░      ░░ ▒░ ░   ▒ ▒▓▒ ▒ ░     ▒ ░░      ░░ ▒░ ░   ░ ▒▓ ░▒▓░"
"    ░        ░ ░  ░   ░ ░▒  ░ ░       ░        ░ ░  ░     ░▒ ░ ▒░"
"  ░            ░      ░  ░  ░       ░            ░        ░░   ░ "
"               ░  ░         ░                    ░  ░      ░     "
    )

    local colors=($PURPLE $CYAN $GREEN $MAGENTA)

    for i in "${!lines[@]}"; do
        color="${colors[$((i % ${#colors[@]}))]}"
        echo -e "${color}${lines[i]}${NC}"
        sleep 0.1
    done
}


# --------------------------
# Início do checker
# --------------------------
clear
print_header

cleanup

TESTES_PASSADOS=0
TESTES_TOTAIS=0
ARQUIVOS_PRESENTES=()
ARQUIVOS_FALTANDO=()

# --------------------------
# Pré-verificação de arquivos .c
# --------------------------
mkdir -p "$BIN_DIR"

for FUNC in "${FUNCOES[@]}"; do
    if [ "$FUNC" = "broken_gnl" ]; then
        if [ -f "Broken_GNL/${FUNC}.c" ]; then
            ARQUIVOS_PRESENTES+=("$FUNC")
        else
            ARQUIVOS_FALTANDO+=("$FUNC")
        fi
    else
        DIR_NAME="$(tr '[:lower:]' '[:upper:]' <<< ${FUNC:0:1})${FUNC:1}"
        if [ -f "${DIR_NAME}/${FUNC}.c" ]; then
            ARQUIVOS_PRESENTES+=("$FUNC")
        else
            ARQUIVOS_FALTANDO+=("$FUNC")
        fi
    fi
done

if [ ${#ARQUIVOS_FALTANDO[@]} -gt 0 ]; then
    echo    # espaço extra antes da caixa
    echo -e "${MAGENTA}    ╔══════════════════════════════════════╗${NC}"
    echo -e "${YELLOW}       ⚠️  ATENÇÃO: ARQUIVOS .C FALTANDO!${NC}"
    echo -e "${MAGENTA}    ──────────────────────────────────────${NC}"
    for file in "${ARQUIVOS_FALTANDO[@]}"; do
        echo -e "${CYAN}      • ${BOLD}${file}${NC}"
    done
    echo -e "${MAGENTA}    ╚══════════════════════════════════════╝${NC}\n"
fi


echo    # espaço extra
echo -e "${MAGENTA}═════════════════════════════════════════════════════${NC}"
echo -e "${CYAN}    💻  --- EXECUTANDO TESTES FUNCIONAIS ---  💻${NC}"
echo -e "${MAGENTA}═════════════════════════════════════════════════════${NC}\n"


# --------------------------
# Loop principal: testa cada função presente
# --------------------------
for FUNC in "${ARQUIVOS_PRESENTES[@]}"; do
    
    BIN_PATH="./$BIN_DIR/${FUNC}_test"
    
    echo -en "  ${CYAN}»${NC} Testing ${BOLD}${PURPLE}${FUNC}${NC}..." 
    TESTES_TOTAIS=$((TESTES_TOTAIS + 1))
    PASSED=1 
    DEBUG_FAIL_MSG=""
    
    # Tentativa de compilar
    SRC_FILE=""
    COMPILE_FLAGS="-Wall -Wextra"
    
    if [ "$FUNC" = "broken_gnl" ]; then
        SRC_FILE="Broken_GNL/${FUNC}.c"
        COMPILE_FLAGS="${COMPILE_FLAGS} -I Broken_GNL"
    else
        DIR_NAME="$(tr '[:lower:]' '[:upper:]' <<< ${FUNC:0:1})${FUNC:1}"
        SRC_FILE="${DIR_NAME}/${FUNC}.c"
        COMPILE_FLAGS="${COMPILE_FLAGS} -I ${DIR_NAME}"
    fi
    
    if [ ! -f "$SRC_FILE" ]; then
        echo -e "${RED} ❌ (Erro interno)${NC}"
        continue
    fi

    if ! gcc "$SRC_FILE" -o "$BIN_PATH" $COMPILE_FLAGS 2> /tmp/compile_errors; then
        echo -e "${RED} ❌ (Erro de compilação)${NC}"
        echo -e "${RED}      Detalhes do Erro: \n$(sed 's/^/      /' /tmp/compile_errors)${NC}" 1>&2
        sleep 0.8
        continue
    fi
    
    chmod +x "$BIN_PATH"
    
    # -----------------------
    # //// FILTER ////
    # -----------------------
    if [ "$FUNC" = "filter" ]; then
        EXEC_CMD="$BIN_PATH"
        SUCCESFUL_TESTS=0
        
        TESTS=(
            "ola mundo" "ola" "*** mundo"
            "A B A B C" "A" "* B * B C"
            "banana" "ana" "b***na"
            "bomdia" "bom" "***dia"
            "abc abc abc" "abc" "*** *** ***"
            "  espaco  " "sp" "  e**aco  "
            "tudobem" "e" "tudob*m"
            "aaaaa" "a" "*****"
            "zxcvbnm" "q" "zxcvbnm"
        )

        for ((i=0; i<${#TESTS[@]}; i+=3)); do
            INPUT_DATA="${TESTS[i]}"
            ARG_FILTRO="${TESTS[i+1]}"
            EXPECTED_OUTPUT="${TESTS[i+2]}"
            TEST_NAME="Teste $((i/3 + 1)) (I:'${INPUT_DATA}', F:'${ARG_FILTRO}')"

            if run_test "echo -n \"${INPUT_DATA}\" | $EXEC_CMD \"${ARG_FILTRO}\"" "$EXPECTED_OUTPUT"; then
                SUCCESFUL_TESTS=$((SUCCESFUL_TESTS + 1))
            else
                PASSED=0 
                DEBUG_FAIL_MSG="${TEST_NAME}"
                break
            fi
        done
        TOTAL_TESTES_FUNCIONAL=$(( ${#TESTS[@]} / 3 ))
        
        # ADICIONAR AQUI O OUTPUT DO RESULTADO
        if [ $PASSED -eq 1 ]; then
            echo -e " ${GREEN} ✅ (${SUCCESFUL_TESTS}/${TOTAL_TESTES_FUNCIONAL})${NC}"
            TESTES_PASSADOS=$((TESTES_PASSADOS + 1))
            sleep 0.8
        else
            echo -e " ${RED} ❌ (${SUCCESFUL_TESTS}/${TOTAL_TESTES_FUNCIONAL})${NC}" 
            echo -e "${RED}      --- DEBUG: ${DEBUG_FAIL_MSG} ---${NC}" 1>&2
            echo "      Esperado (cat -e):" 1>&2
            cat -e /tmp/output_expected 1>&2
            echo "      Obtido (cat -e):" 1>&2
            cat -e /tmp/output_actual 1>&2
            echo -e "${RED}      ---------------------------------${NC}" 1>&2
            sleep 0.8
        fi
        
    # -----------------------
    # //// BROKEN_GNL ////
    # -----------------------
    elif [ "$FUNC" = "broken_gnl" ]; then
        EXEC_CMD="$BIN_PATH"
        SUCCESFUL_TESTS=0
        
        GNL_TESTS=(
            "Linha 1\nLinha 2\nLinha 3\n" "Line : Linha 1\nLine : Linha 2\nLine : Linha 3"
            "Esta é a primeira linha longa.\nE esta é a segunda linha longa.\n" "Line : Esta é a primeira linha longa.\nLine : E esta é a segunda linha longa."
            "" ""
            "Sem quebra final" ""
            "a\nb\nc\nd\n" "Line : a\nLine : b\nLine : c\nLine : d"
            "\n\n\nFinal" "Line : \nLine : \nLine : "
        )
        
        for ((i=0; i<${#GNL_TESTS[@]}; i+=2)); do
            FILE_CONTENT="${GNL_TESTS[i]}"
            EXPECTED_OUTPUT="${GNL_TESTS[i+1]}"
            TEST_NAME="Teste $((i/2 + 1))"

            echo -e -n "$FILE_CONTENT" > /tmp/test_file_gnl

            timeout 2s "$EXEC_CMD" /tmp/test_file_gnl > /tmp/output_actual 2> /tmp/gnl_err
            EXIT_CODE=$?
            
            if [ $EXIT_CODE -ne 0 ] && [ $EXIT_CODE -ne 1 ]; then
                PASSED=0
                if [ $EXIT_CODE -eq 124 ]; then
                    DEBUG_FAIL_MSG="${TEST_NAME} (TIMEOUT)"
                elif [ $EXIT_CODE -eq 139 ]; then 
                    DEBUG_FAIL_MSG="${TEST_NAME} (SEG FAULT)"
                else 
                    DEBUG_FAIL_MSG="${TEST_NAME} (RUNTIME ERROR: $EXIT_CODE)"
                fi
                break 
            fi

            if [ -z "$EXPECTED_OUTPUT" ]; then
                echo -n "" > /tmp/output_expected
            else
                echo -e "$EXPECTED_OUTPUT" > /tmp/output_expected
            fi
            
            if ! diff /tmp/output_actual /tmp/output_expected > /dev/null; then
                 PASSED=0
                 DEBUG_FAIL_MSG="${TEST_NAME} (Diferença de Output)"
                 break
            fi
            
            SUCCESFUL_TESTS=$((SUCCESFUL_TESTS + 1))
        done
        
        TOTAL_TESTES_FUNCIONAL=$(( ${#GNL_TESTS[@]} / 2 ))

        if [ $PASSED -eq 1 ]; then
            echo -e " ${GREEN} ✅ (${SUCCESFUL_TESTS}/${TOTAL_TESTES_FUNCIONAL})${NC}"
            TESTES_PASSADOS=$((TESTES_PASSADOS + 1))
            sleep 0.8
        else
            echo -e "${RED} ❌ (${SUCCESFUL_TESTS}/${TOTAL_TESTES_FUNCIONAL})${NC}" 
            
            if [ "$TEST_NAME" = "Teste 4" ] || [ "$TEST_NAME" = "Teste 6" ]; then
                echo -e "${RED}      --- DEBUG: ERRO ESPERADO: BUG de EOF/Falta de \\n no GNL. ---${NC}" 1>&2
            else
                echo -e "${RED}      --- DEBUG: ${DEBUG_FAIL_MSG} ---${NC}" 1>&2
            fi
            
            echo "      Esperado (cat -e):" 1>&2
            cat -e /tmp/output_expected 1>&2
            echo "      Obtido (cat -e):" 1>&2
            cat -e /tmp/output_actual 1>&2
            echo -e "${RED}      ---------------------------------${NC}" 1>&2
            
            sleep 0.8
        fi

    # -----------------------
    # //// SCANF ////
    # -----------------------
    elif [ "$FUNC" = "scanf" ]; then
        EXEC_CMD="$BIN_PATH"
        SUCCESFUL_TESTS=0

        TESTS=(
            "%s %d %c"   "Projeto 42 F"   "3" "Projeto"   "42" "F" "0"
            "%s %d"      "Hello  -100"    "2" "Hello"     "-100" " "  "0"
            "%s %d %c"   "Falta_Char 5"   "2" "Falta_Char" "5"  " "  "0"
            "%s %d %c"      ""               "-1" ""          "0" " "  "0"
            "%s"         "apenas_string 1"  "1" "apenas_string" "0" " "  "0"
        )
        
        for ((i=0; i<${#TESTS[@]}; i+=7)); do
            FORMAT="${TESTS[i]}"
            INPUT_DATA="${TESTS[i+1]}"
            N_CONV_EXPECTED="${TESTS[i+2]}"
            S_VAL_EXPECTED="${TESTS[i+3]}"
            D_VAL_EXPECTED="${TESTS[i+4]}"
            C_VAL_EXPECTED="${TESTS[i+5]}"
            D2_VAL_EXPECTED="${TESTS[i+6]}"
            TEST_NAME="Teste $((i/7 + 1)) (F:$FORMAT, I:$INPUT_DATA)"
            
            C_VAL_PRINTED="${C_VAL_EXPECTED}"
            
            EXPECTED_OUTPUT=$(printf "Format: %s\nNConv: %s\ns_val: %s\nd_val: %s\nc_val: %s\nd2_val: %s" \
                                        "$FORMAT" "$N_CONV_EXPECTED" "$S_VAL_EXPECTED" \
                                        "$D_VAL_EXPECTED" "$C_VAL_PRINTED" "$D2_VAL_EXPECTED")

            if run_test "echo -n \"${INPUT_DATA}\" | $EXEC_CMD \"$FORMAT\"" "$EXPECTED_OUTPUT"; then
                SUCCESFUL_TESTS=$((SUCCESFUL_TESTS + 1))
            else
                PASSED=0 
                DEBUG_FAIL_MSG="Falha no ${TEST_NAME}"
                break 
            fi
        done
        TOTAL_TESTES_FUNCIONAL=$(( ${#TESTS[@]} / 7 ))
        
        # ADICIONAR AQUI O OUTPUT DO RESULTADO
        if [ $PASSED -eq 1 ]; then
            echo -e " ${GREEN} ✅ (${SUCCESFUL_TESTS}/${TOTAL_TESTES_FUNCIONAL})${NC}"
            TESTES_PASSADOS=$((TESTES_PASSADOS + 1))
            sleep 0.8
        else
            echo -e " ${RED} ❌ (${SUCCESFUL_TESTS}/${TOTAL_TESTES_FUNCIONAL})${NC}" 
            echo -e "${RED}      --- DEBUG: ${DEBUG_FAIL_MSG} ---${NC}" 1>&2
            echo "      Esperado (cat -e):" 1>&2
            cat -e /tmp/output_expected 1>&2
            echo "      Obtido (cat -e):" 1>&2
            cat -e /tmp/output_actual 1>&2
            echo -e "${RED}      ---------------------------------${NC}" 1>&2
            sleep 0.8
        fi
     
    # -----------------------
    # //// N_QUEENS ////
    # -----------------------
    elif [ "$FUNC" = "n_queens" ]; then
    EXEC_CMD="$BIN_PATH"
    SUCCESFUL_TESTS=0
    
    # IMPORTANTE: Garanta que você tenha uma pasta 'solucoes' com os arquivos 'expected_n_N.txt'
    SOLUTIONS_DIR="./solucoes"

    N_QUEENS_TESTS=(
        "1" "1"
        "2" "0"
        "3" "0"
        "4" "2"
        "5" "10"
        "6" "4"
        "7" "40"
        "8" "92"
        "0" "0"
        "9" "352"
    )

    for ((i=0; i<${#N_QUEENS_TESTS[@]}; i+=2)); do
        N="${N_QUEENS_TESTS[i]}"
        EXPECTED_COUNT="${N_QUEENS_TESTS[i+1]}"
        TEST_NAME="Teste $((i/2 + 1)) (N=$N - Contagem esperada: $EXPECTED_COUNT)"
        PASSED_CURRENT_TEST=1 # Assume sucesso inicialmente

        # Define o arquivo de referência (que você deve ter criado)
        EXPECTED_FILE="$SOLUTIONS_DIR/expected_n_${N}.txt"

        # 1. EXECUTA o programa, ORDENA a saída e salva em /tmp/output_actual
        # A ordenação (-n) garante que a ordem das soluções não falhe o teste.
        $EXEC_CMD $N | sort -n > /tmp/output_actual 2>/dev/null 

        # 2. Verifica a CONTENÇÃO (N=0, N=2, N=3) e se o arquivo de referência existe
        if [ "$EXPECTED_COUNT" -eq "0" ]; then
            # Se a contagem esperada é 0, a saída atual deve ter 0 linhas.
            ACTUAL_COUNT=$(wc -l < /tmp/output_actual)
            if [ "$ACTUAL_COUNT" -ne "0" ]; then
                PASSED_CURRENT_TEST=0
                DEBUG_FAIL_MSG="Contagem ERRADA (Esperado 0, Obtido $ACTUAL_COUNT)"
            fi
        elif [ ! -f "$EXPECTED_FILE" ]; then
            # Este é um erro do tester, não do seu código
            echo -e "${RED} ❌ ERRO DO TESTER: Arquivo de referência $EXPECTED_FILE não encontrado!${NC}" 1>&2
            PASSED=0
            break
        else
            # 3. Processa testes com soluções (> 0)
            
            # Conta a saída atual para verificação rápida
            ACTUAL_COUNT=$(wc -l < /tmp/output_actual)

            # Ordena o arquivo de referência e salva em /tmp/output_expected_sorted
            sort -n "$EXPECTED_FILE" > /tmp/output_expected_sorted

            # 4. CHECA: A contagem e o conteúdo (usando cmp -s para comparação silenciosa de arquivos)
            if [ "$ACTUAL_COUNT" -ne "$EXPECTED_COUNT" ]; then
                PASSED_CURRENT_TEST=0
                DEBUG_FAIL_MSG="Contagem ERRADA (Esperado $EXPECTED_COUNT, Obtido $ACTUAL_COUNT)"
            # Se a contagem estiver OK, checa o conteúdo (a ordem não importa pois ambos foram 'sorted')
            elif ! cmp -s /tmp/output_actual /tmp/output_expected_sorted; then
                PASSED_CURRENT_TEST=0
                DEBUG_FAIL_MSG="Conteúdo INCOMPLETO/INCORRETO (Contagem OK, mas soluções diferentes)"
            fi
        fi

        if [ "$PASSED_CURRENT_TEST" -eq "1" ]; then
            SUCCESFUL_TESTS=$((SUCCESFUL_TESTS + 1))
        else
            PASSED=0 
            DEBUG_FAIL_MSG="${TEST_NAME}"
            break # Falha no primeiro erro
        fi
    done
    
    TOTAL_TESTES_FUNCIONAL=$(( ${#N_QUEENS_TESTS[@]} / 2 ))
    
    # ADICIONAR AQUI O OUTPUT DO RESULTADO (ESTE TRECHO NÃO FOI ALTERADO)
    if [ $PASSED -eq 1 ]; then
        echo -e " ${GREEN} ✅ (${SUCCESFUL_TESTS}/${TOTAL_TESTES_FUNCIONAL})${NC}"
        TESTES_PASSADOS=$((TESTES_PASSADOS + 1))
        sleep 0.8
    else
        echo -e " ${RED} ❌ (${SUCCESFUL_TESTS}/${TOTAL_TESTES_FUNCIONAL})${NC}" 
        echo -e "${RED}      --- DEBUG: ${DEBUG_FAIL_MSG} ---${NC}" 1>&2
        
        # Redireciona o output esperado/obtido para a saída de erro (stderr)
        if [ -f "/tmp/output_expected_sorted" ]; then
            echo "      Esperado (Conteúdo Ordenado):" 1>&2
            cat -e /tmp/output_expected_sorted 1>&2
        fi
        
        echo "      Obtido (Conteúdo Ordenado):" 1>&2
        cat -e /tmp/output_actual 1>&2
        echo -e "${RED}      ---------------------------------${NC}" 1>&2
        sleep 0.8
    fi
    # -----------------------
    # //// PERMUTATIONS ////
    # -----------------------
    elif [ "$FUNC" = "permutations" ]; then
        EXEC_CMD="$BIN_PATH"
        SUCCESFUL_TESTS=0
       PERM_TESTS=(
            # 1. Caso Trivial (1 caractere)
            "a" "a" "0"

            # 2. Caso Base (2 caracteres)
            "ab" "ab\nba" "0"

            # 3. Caso Base (3 caracteres)
            "abc" "abc\nacb\nbac\nbca\ncab\ncba" "0"

            # 4. Caso de Desordem Inicial (4 caracteres desordenados)
            "dcba" "abcd\nabdc\nacbd\nacdb\nadbc\nadcb\nbacd\nbadc\nbcad\nbcda\nbdac\nbdca\ncabd\ncadb\ncbad\ncbda\ncdab\ncdba\ndabc\ndacb\ndbac\ndbca\ndcab\ndcba" "0"

            # 5. String com caracteres repetidos
            "aab" "aab\naab\naba\naba\nbaa\nbaa" "0"

            # 6. String já ordenada (4 caracteres)
            "abcd" "abcd\nabdc\nacbd\nacdb\nadbc\nadcb\nbacd\nbadc\nbcad\nbcda\nbdac\nbdca\ncabd\ncadb\ncbad\ncbda\ncdab\ncdba\ndabc\ndacb\ndbac\ndbca\ndcab\ndcba" "0"

            # 7. String com números e letras
            "1a2" "12a\n1a2\n21a\n2a1\na21\na12" "0"            

        )
        
        for ((i=0; i<${#PERM_TESTS[@]}; i+=3)); do
            INPUT="${PERM_TESTS[i]}"
            EXPECTED_OUTPUT="${PERM_TESTS[i+1]}"
            TEST_NAME="Teste $((i/3 + 1)) (I:'$INPUT')"

            if run_multi_test "$EXEC_CMD $INPUT" "$EXPECTED_OUTPUT" "${TEST_NAME}"; then
                SUCCESFUL_TESTS=$((SUCCESFUL_TESTS + 1))
            else
                PASSED=0 
                break
            fi
        done
        TOTAL_TESTES_FUNCIONAL=$(( ${#PERM_TESTS[@]} / 3 ))
        
        # ADICIONAR AQUI O OUTPUT DO RESULTADO
        if [ $PASSED -eq 1 ]; then
            echo -e " ${GREEN} ✅ (${SUCCESFUL_TESTS}/${TOTAL_TESTES_FUNCIONAL})${NC}"
            TESTES_PASSADOS=$((TESTES_PASSADOS + 1))
            sleep 0.8
        else
            echo -e " ${RED} ❌ (${SUCCESFUL_TESTS}/${TOTAL_TESTES_FUNCIONAL})${NC}" 
            echo -e "${RED}      --- DEBUG: ${DEBUG_FAIL_MSG} ---${NC}" 1>&2
            echo "      Esperado (ordenado):" 1>&2
            cat /tmp/output_expected_sorted 1>&2
            echo "      Obtido (ordenado):" 1>&2
            cat /tmp/output_actual_sorted 1>&2
            echo -e "${RED}      ---------------------------------${NC}" 1>&2
            sleep 0.8
        fi

    # -----------------------
    # //// POWERSET ////
    # -----------------------
    elif [ "$FUNC" = "powerset" ]; then
        EXEC_CMD="$BIN_PATH"
        SUCCESFUL_TESTS=0
        
        POWERSET_TESTS=(
            "" "\n" "1"
            "a" "\na" "2"
            "ab" "\na\nb\nab" "4"
            "abc" "\na\nb\nc\nab\nac\nbc\nabc" "8"
            "1234" "\n1\n2\n3\n4\n12\n13\n14\n23\n24\n34\n123\n124\n134\n234\n1234" "16"
            "aaa" "\n" "6"
            "112" "\n1\n2\n12" "7"
            "wxy" "\nw\nx\ny\nwx\nwy\nxy\nwxy" "8"
        )
        
        for ((i=0; i<${#POWERSET_TESTS[@]}; i+=3)); do
            INPUT="${POWERSET_TESTS[i]}"
            EXPECTED_OUTPUT="${POWERSET_TESTS[i+1]}"
            TEST_NAME="Teste $((i/3 + 1)) (I:'$INPUT')"

            if run_multi_test "$EXEC_CMD $INPUT" "$EXPECTED_OUTPUT" "${TEST_NAME}"; then
                SUCCESFUL_TESTS=$((SUCCESFUL_TESTS + 1))
            else
                PASSED=0 
                break
            fi
        done
        TOTAL_TESTES_FUNCIONAL=$(( ${#POWERSET_TESTS[@]} / 3 ))
        
        # ADICIONAR AQUI O OUTPUT DO RESULTADO
        if [ $PASSED -eq 1 ]; then
            echo -e " ${GREEN} ✅ (${SUCCESFUL_TESTS}/${TOTAL_TESTES_FUNCIONAL})${NC}"
            TESTES_PASSADOS=$((TESTES_PASSADOS + 1))
            sleep 0.8
        else
            echo -e " ${RED} ❌ (${SUCCESFUL_TESTS}/${TOTAL_TESTES_FUNCIONAL})${NC}" 
            echo -e "${RED}      --- DEBUG: ${DEBUG_FAIL_MSG} ---${NC}" 1>&2
            echo "      Esperado (ordenado):" 1>&2
            cat /tmp/output_expected_sorted 1>&2
            echo "      Obtido (ordenado):" 1>&2
            cat /tmp/output_actual_sorted 1>&2
            echo -e "${RED}      ---------------------------------${NC}" 1>&2
            sleep 0.8
        fi


    # -----------------------
    # //// RIP ////
    # -----------------------
    elif [ "$FUNC" = "rip" ]; then
        EXEC_CMD="$BIN_PATH"
        SUCCESFUL_TESTS=0
        TOTAL_TESTES_FUNCIONAL=0
        PASSED=1  # Assume todos passaram até que falhe

        RIP_TESTS=(
            "(()" "( )\n ()"
            "((()()())())" "((()()())())"
            "()())()" "( ())()$\n()( )()$\n()() ()$"
            "(()(()(" " () () $\n ()( ) $\n( ) () $\n( )( ) $\n(()  ) $"
        )

        for ((i=0; i<${#RIP_TESTS[@]}; i+=2)); do
            INPUT="${RIP_TESTS[i]}"
            EXPECTED_OUTPUT="${RIP_TESTS[i+1]}"
            TEST_NAME="Teste $((i/2 + 1)) (I:'$INPUT')"
            TOTAL_TESTES_FUNCIONAL=$((TOTAL_TESTES_FUNCIONAL + 1))

            # Executa o programa
            OBTIDO=$( "$EXEC_CMD" "$INPUT" 2>&1 )

            # Normaliza linhas e remove caracteres '$' que o cat -e adiciona
            OBTIDO_NORM=$(echo -e "$OBTIDO" | sed 's/\$$//' | sed '/^[[:space:]]*$/s/.*/ /' | sort -u)
            EXPECTED_NORM=$(echo -e "$EXPECTED_OUTPUT" | sed 's/\$$//' | sed '/^[[:space:]]*$/s/.*/ /' | sort -u)

            # Comparação sem imprimir resultado a cada teste
            if [ "$OBTIDO_NORM" = "$EXPECTED_NORM" ]; then
                SUCCESFUL_TESTS=$((SUCCESFUL_TESTS + 1))
            else
                PASSED=0
                DEBUG_FAIL_MSG="${TEST_NAME}"
                break
            fi
        done
        
        if [ $PASSED -eq 1 ]; then
            echo -e " ${GREEN} ✅ (${SUCCESFUL_TESTS}/${TOTAL_TESTES_FUNCIONAL})${NC}"
            TESTES_PASSADOS=$((TESTES_PASSADOS + 1))
            sleep 0.8
        elif [ $PASSED -eq 0 ]; then
            echo -e " ${RED} ❌ (${SUCCESFUL_TESTS}/${TOTAL_TESTES_FUNCIONAL})${NC}" 
            echo -e "${RED}      --- DEBUG: ${DEBUG_FAIL_MSG} ---${NC}" 1>&2
            
            echo "      Esperado (cat -e):" 1>&2
            cat -e /tmp/output_expected 1>&2
            echo "      Obtido (cat -e):" 1>&2
            cat -e /tmp/output_actual 1>&2
            echo -e "${RED}      ---------------------------------${NC}" 1>&2
            sleep 0.8
        fi
    fi
done 

# --------------------------
# Resumo final (estético)
# --------------------------
echo    # espaço extra
echo -e "${MAGENTA}═════════════════════════════════════════════════════${NC}"
echo -e "${CYAN}       💻  --- RESUMO DOS TESTES ---  💻${NC}"
echo -e "${MAGENTA}═════════════════════════════════════════════════════${NC}\n"

TOTAL_FUNCOES_TESTADAS=${#ARQUIVOS_PRESENTES[@]}
TESTES_REPROVADOS=$(( TOTAL_FUNCOES_TESTADAS - TESTES_PASSADOS ))

if [ $TESTES_REPROVADOS -lt 0 ]; then
    TESTES_REPROVADOS=0
fi

echo -e "  ${BOLD}Total de Funções Testadas:${NC} ${CYAN}${TOTAL_FUNCOES_TESTADAS}${NC}"
echo -e "  ${BOLD}Testes Aprovados:${NC} ${GREEN}${TESTES_PASSADOS}${NC} / ${CYAN}${TOTAL_FUNCOES_TESTADAS}${NC}"
echo -e "  ${BOLD}Testes Reprovados:${NC} ${RED}${TESTES_REPROVADOS}${NC}"

FALTANTES=$(( ${#FUNCOES[@]} - TOTAL_FUNCOES_TESTADAS ))
if [ $FALTANTES -gt 0 ]; then
    echo -e "\n  ${BOLD}Arquivos Faltando/Não Compilados:${NC} ${YELLOW}${FALTANTES}${NC} (Verifique acima)"
fi

echo -e "\n${MAGENTA}────────────────────────────────────────────────────────────────${NC}\n"

# Limpeza
cleanup