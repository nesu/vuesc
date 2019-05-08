param (
    # Vues code input
    [Parameter(Mandatory=$true)][string]$vsi = "",
    [Parameter(Mandatory=$true)][string]$output = "",
    [string]$debug_type = "UNSPECIFIED",
    [switch]$parser_debug = $false,
    [string]$compiler = "D:\\vuesc\\compiler\\Debug\\compiler.exe"
)

$prsd = ""
if ($parser_debug -eq $true) {
    $prsd = "-parser-debug-level=1"
}

Write-Host $parser_debug

& $compiler -o ".vuesc/$($output).bc" $prsd "-debug-only=$($debug_type)" $vsi
& llc -filetype=obj ".vuesc/$($output).bc"
& lld-link -out:"$($output).exe" -defaultlib:libcmt "-libpath:C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\BuildTools\\VC\\Tools\\MSVC\\14.16.27023\\lib\\x64" "-libpath:C:\\Program Files (x86)\\Windows Kits\\10\\Lib\\10.0.17763.0\\ucrt\\x64" "-libpath:C:\\Program Files (x86)\\Windows Kits\\10\\Lib\\10.0.17763.0\\um\\x64" -nologo ".vuesc/$($output).obj"