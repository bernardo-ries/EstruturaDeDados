using System;

public class Processo
{
    public int Id { get; set; }
    public string Descricao { get; set; }
    public Processo(int id, string descricao)
    {
        Id = id;
        Descricao = descricao;
    }

    public override bool Equals(object obj)
    {
        return obj is Processo processo && processo.Id == this.Id;
    }

    public override int GetHashCode()
    {
        return Id.GetHashCode();
    }

    public override string ToString()
    {
        return $"ID: {Id}, Descrição: {Descricao}";
    }
}
   