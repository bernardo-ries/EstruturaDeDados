using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;

public class Program
{
    public static void gerarProcessoEmFilas(Queue<Processo> filaPrioritaria, Queue<Processo> filaNormal, int quantidadeProcessos)
    {
        Random rnd = new Random();
        int numeroProcessoGerado;
        for (int i = 0; i < quantidadeProcessos; i++)
        {
            numeroProcessoGerado = rnd.Next(0, 1001);
            switch (numeroProcessoGerado)
            {
                case 0:
                    if (filaPrioritaria.Count > 0)
                    {
                        Processo atendido = filaPrioritaria.Dequeue();
                        Console.WriteLine("Atendendo: " + atendido);
                    }
                    else
                    {
                        Console.WriteLine("Fila vazia!");
                    }
                    break;
                case 500:
                    if (filaNormal.Count > 0)
                    {
                        Processo atendido = filaNormal.Dequeue();
                        Console.WriteLine("Atendendo: " + atendido);
                    }
                    else
                    {
                        Console.WriteLine("Fila vazia!");
                    }
                    break;
                default:
                    if (numeroProcessoGerado < 500)
                    {
                        Processo processoTmp = new Processo(numeroProcessoGerado, "Processo de alta prioridade");
                        filaPrioritaria.Enqueue(processoTmp);
                        Console.WriteLine(processoTmp);

                    }
                    else
                    {
                        Processo processoTmp = new Processo(numeroProcessoGerado, "Processo de baixa prioridade");
                        filaNormal.Enqueue(processoTmp);
                        Console.WriteLine(processoTmp);
                    }
                    break;
            }
        }
    }
    public static void exibirProcessosNaoAtendidos(Queue<Processo> fila, String frase)
    {
        Console.WriteLine(frase);
        Console.WriteLine("Total de processos nao atendidos: " + fila.Count());
    }



    public static void Main(String[] args)
    {
        Queue<Processo> filaPrioritaria = new Queue<Processo>();
        Queue<Processo> filaNormal = new Queue<Processo>();

        gerarProcessoEmFilas(filaPrioritaria, filaNormal, 1000);

    }
}