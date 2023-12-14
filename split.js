const nome = ""
const palavras = []
let ultimoSplit = 0;

for (let i = 0; i < nome.length; i++) {
	if (i === nome.length - 1) palavras.push(nome.substring(ultimoSplit, i + 1))
	else if (nome[i] === " ") {
		palavras.push(nome.substring(ultimoSplit, i))
		ultimoSplit = i + 1
	}
}

for (let i = 0; i < palavras.length; i++) {
	if (i !== 0 && i !== palavras.length - 1) palavras[i] = (palavras[i][0]).toString().toUpperCase()
}

console.log(palavras.join(" "))