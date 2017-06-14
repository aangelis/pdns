/*
 * This file is part of PowerDNS or dnsdist.
 * Copyright -- PowerDNS.COM B.V. and its contributors
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * In addition, for the avoidance of any doubt, permission is granted to
 * link this program with OpenSSL and to (re)distribute the binaries
 * produced as the result of such linking.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */
#include "namespaces.hh"
#include "iputils.hh"
#include "dnsparser.hh"

//! retrieve IXFR deltas from master, from a local address
vector<pair<vector<DNSRecord>, vector<DNSRecord> > >   getIXFRDeltas(const ComboAddress& master, const DNSName& zone, 
                                                                     const DNSRecord& sr, const TSIGTriplet& tt=TSIGTriplet(),
                                                                     const ComboAddress* laddr=0, size_t maxReceivedBytes=0);

//! retrieve IXFR deltas over a ready to use socket (which we close for you when we are done)
vector<pair<vector<DNSRecord>, vector<DNSRecord> > > getIXFRDeltas(int fd, const ComboAddress& master, const DNSName& zone, const DNSRecord& oursr, 
                                                                   const TSIGTriplet& tt=TSIGTriplet(), size_t maxReceivedBytes=0);
