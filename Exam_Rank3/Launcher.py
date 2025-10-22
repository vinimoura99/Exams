import os
import subprocess
import tkinter as tk
from tkinter import messagebox

def listar_arquivos():
    lista.delete(0, tk.END)
    for root, dirs, files in os.walk('.'):
        for f in files:
            if f.endswith('.c'):
                caminho = os.path.join(root, f)
                lista.insert(tk.END, caminho)
    saida_text.delete(1.0, tk.END)
    saida_text.insert(tk.END, "Arquivos listados com sucesso!\n")

def compilar_rodar():
    arquivo = lista.get(tk.ACTIVE)
    if not arquivo:
        messagebox.showwarning("Aviso", "Nenhum arquivo selecionado.")
        return

    nome_exec = "programa_temp"

    try:
        # Remove binário antigo se existir
        if os.path.exists(nome_exec):
            os.remove(nome_exec)

        # Compila o programa C
        subprocess.run(["gcc", arquivo, "-o", nome_exec], check=True)

        # Captura argv e stdin do usuário
        args_usuario = args_entry.get().strip().split()  # lista de argumentos
        entrada_usuario = input_entry.get("1.0", tk.END).rstrip("\n")  # remove newline final

        # Prepara o comando
        comando = ["./" + nome_exec] + args_usuario

        # Executa o binário
        resultado = subprocess.run(
            comando,
            input=entrada_usuario if entrada_usuario else None,
            capture_output=True,
            text=True
        )

        # Limpa saída e mostra stdout
        saida_text.delete(1.0, tk.END)
        saida_text.insert(tk.END, resultado.stdout)

        # Mostra stderr, se houver
        if resultado.stderr:
            messagebox.showerror("Erro do programa", resultado.stderr)

    except subprocess.CalledProcessError as e:
        messagebox.showerror("Erro de compilação", f"Falha ao compilar:\n{e}")
    finally:
        if os.path.exists(nome_exec):
            os.remove(nome_exec)

def limpar_saida():
    saida_text.delete(1.0, tk.END)
    input_entry.delete(1.0, tk.END)
    args_entry.delete(0, tk.END)

def sair():
    janela.destroy()

# ---- Interface ----
janela = tk.Tk()
janela.title("🧠 C Test Launcher by Vinicius Moura")
janela.geometry("750x650")
janela.configure(bg="#1E1E1E")

titulo = tk.Label(janela, text="🧠 C Test Launcher", fg="white", bg="#1E1E1E", font=("Consolas", 18, "bold"))
titulo.pack(pady=10)

frame_botoes = tk.Frame(janela, bg="#1E1E1E")
frame_botoes.pack(pady=5)

tk.Button(frame_botoes, text="Listar Arquivos", command=listar_arquivos, width=15, bg="#3C3C3C", fg="white").grid(row=0, column=0, padx=5)
tk.Button(frame_botoes, text="Compilar e Rodar", command=compilar_rodar, width=15, bg="#3C3C3C", fg="white").grid(row=0, column=1, padx=5)
tk.Button(frame_botoes, text="Limpar Saída", command=limpar_saida, width=15, bg="#3C3C3C", fg="white").grid(row=0, column=2, padx=5)
tk.Button(frame_botoes, text="Sair", command=sair, width=15, bg="#3C3C3C", fg="white").grid(row=0, column=3, padx=5)

lista_label = tk.Label(janela, text="Arquivos encontrados:", fg="white", bg="#1E1E1E", anchor="w")
lista_label.pack(fill="x", padx=20)
lista = tk.Listbox(janela, width=100, height=8, bg="#252526", fg="white", selectbackground="#007ACC", font=("Consolas", 10))
lista.pack(padx=20, pady=5)

args_label = tk.Label(janela, text="Argumentos (argv):", fg="white", bg="#1E1E1E", anchor="w")
args_label.pack(fill="x", padx=20)
args_entry = tk.Entry(janela, width=100, bg="#252526", fg="#9CDCFE", insertbackground="white", font=("Consolas", 10))
args_entry.pack(padx=20, pady=5)

input_label = tk.Label(janela, text="Entrada do programa (stdin):", fg="white", bg="#1E1E1E", anchor="w")
input_label.pack(fill="x", padx=20)
input_entry = tk.Text(janela, height=4, width=100, bg="#252526", fg="#DCDCAA", insertbackground="white", font=("Consolas", 10))
input_entry.pack(padx=20, pady=5)

saida_label = tk.Label(janela, text="Saída do programa:", fg="white", bg="#1E1E1E", anchor="w")
saida_label.pack(fill="x", padx=20)
saida_text = tk.Text(janela, height=14, width=100, bg="#252526", fg="white", insertbackground="white", font=("Consolas", 10))
saida_text.pack(padx=20, pady=5)

listar_arquivos()
janela.mainloop()
