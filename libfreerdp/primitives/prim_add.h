/* FreeRDP: A Remote Desktop Protocol Client
 * Add operations.
 * vi:ts=4 sw=4
 *
 * (c) Copyright 2012 Hewlett-Packard Development Company, L.P.
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License. You may obtain
 * a copy of the License at http://www.apache.org/licenses/LICENSE-2.0.
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
 * or implied. See the License for the specific language governing
 * permissions and limitations under the License.  Algorithms used by
 * this code may be covered by patents by HP, Microsoft, or other parties.
 *
 */

#ifdef __GNUC__
# pragma once
#endif

#ifndef __PRIM_ADD_H_INCLUDED__
#define __PRIM_ADD_H_INCLUDED__

pstatus_t general_add_16s(const INT16 *pSrc1, const INT16 *pSrc2, INT16 *pDst, INT32 len);

void primitives_init_add_opt(const primitives_hints_t *hints, primitives_t *prims);

#endif /* !__PRIM_ADD_H_INCLUDED__ */

